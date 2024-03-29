//#include <mlx.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
//#include "vector/vec3.h"
#include "vector/ray.h"
#include "vector/scene.h"
#include "vector/object.h"

typedef struct 	s_data
{
	void	*mlx;
	void	*mlx_win;
	int		width, height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenth;
	int		endian;
	t_camera	cam;
	t_sphere	sp;
}						t_data;

// 카메라에서 출발한 광선
t_ray	*ft_camera_cal_ray(t_ray *target, t_camera *cam,
							 float u, float v)
{
	t_vec3 cal;

	cal.x = cam->lower_left_corner.x
			+ u * cam->horizontal.x
			+ v * cam->vertical.x
			- cam->orig.x;
	cal.y = cam->lower_left_corner.y
			+ u * cam->horizontal.y
			+ v * cam->vertical.y
			- cam->orig.y;
	cal.z = cam->lower_left_corner.z
			+ u * cam->horizontal.z
			+ v * cam->vertical.z
			- cam->orig.z;
	return (ft_ray_set(target, &(cam->orig), &cal));
}

t_bool	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double	a;
	double	b;
	double	c;

	ft_vec3_sub(&oc, &ray->orig, &sp->center);
	a = ft_vec3_dot(&ray->dir, &ray->dir);
	b = 2.0 * ft_vec3_dot(&oc, &ray->dir);
	c = ft_vec3_dot(&oc, &oc) - sp->radius_squared;
	return (b * b - 4 * a * c > 0); // 0보다 크다면 광선이 구를 hit한 것!
}

// 레이트레이싱을 통해 픽셀의 색깔을 결정
t_color3	*ft_ray_color(t_color3 *target, t_ray *r, t_sphere *sphere)
{
	t_vec3	unit_dir;
	float t;
	t_color3 cal1;
	t_color3 cal2;

	if (hit_sphere(sphere, r))
		return (ft_vec3_set_xyz(target, 1, 0, 0));
	ft_vec3_unit_vec(&unit_dir, &(r->dir));
	t = 0.5 * (unit_dir.y + 1.0);
	 // (1-t) * 흰색 + t * 하늘색
	ft_vec3_multi_scalar(&cal1, (1.0 - t),
			ft_vec3_set_xyz(&cal1, 1.0, 1.0, 1.0));
	ft_vec3_multi_scalar(&cal2, t, ft_vec3_set_xyz(&cal2, 0.5, 0.7, 1.0)); // CMY(Cyan Magenta Yellow)
	return (ft_vec3_add(target, &cal1, &cal2));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, t_color3 *color)
{
	char	*dst;

	dst = data->addr
		+ (y * data->line_lenth + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = ((int)color->x << 16) | ((int)color->y << 8) | (int)color->z;
}

int ft_draw(t_data *data)
{
	int			i;
	int			j;
	t_ray		ray;
	t_color3		color;

	j = data->height - 1;
	while (j >= 0)
	{
		i = 0;
		ft_putstr_fd("\rScanlines remaining: ", 1);
		ft_putnbr_fd(j, 1);
		ft_putchar_fd(' ', 1);
		while (i < data->width)
		{
			ft_camera_cal_ray(&ray, &data->cam, (double)i / (data->width - 1), (double)j / (data->height - 1));
			ft_ray_color(&color, &ray, &data->sp);
			ft_vec3_multi_scalar(&color, 255.999, &color);
			my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int main_loop(t_data *data)
{
	ft_draw(data);
	return (0);
}

int main(void)
{
	t_data		data;
	t_point3	center;
	float		aspect_ratio;

	//ft_vec3_set_xyz(&center, 0, 0, -5);
	//ft_sphere_set(&data.sp, center, 2);
	ft_vec3_set_xyz(&center, 0, 0, -1);
	ft_sphere_set(&data.sp, center, 0.5);
	data.mlx = mlx_init();
	//data.width = 600;
	//data.height = 400;
	aspect_ratio = 16.0 / 9.0;
	data.width = 400;
	data.height = data.width / aspect_ratio;
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenth, &data.endian);
	ft_camera_set(&data.cam, data.width / data.height);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
