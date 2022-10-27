#include <mlx.h>
// #include "mlx/mlx.h"
#include "libft.h"
#include "ray.h"
#include "scene.h"
#include "object.h"
#include <math.h>

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
	t_object	*world;
}						t_data;

// 레이트레이싱을 통해 픽셀의 색깔을 결정
t_color3	*ft_ray_color(t_color3 *target, t_ray *r, t_object *world)
{
	t_vec3			unit_dir;
	double			t;
	t_color3		cal1;
	t_color3		cal2;
	t_vec3			n; // [-1, 1] 로 정규화된 법선 -> [0, 1]
	t_hit_record	rec;
	t_point3		tmp;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	if (hit(world, r, &rec))
	{
		// ft_vec3_add_scalar(&tmp, 1, &rec.normal);
		// return (ft_vec3_multi_scalar(target, 0.5, &tmp));
		return (ft_vec3_multi_scalar(target, 0.5, ft_vec3_add_scalar(target, 1, &rec.normal)));
	}
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
			ft_ray_color(&color, &ray, data->world);
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

#include <stdio.h>

int main(void)
{
	t_data		data;
	t_point3	center;
	double		aspect_ratio;

	//ft_vec3_set_xyz(&center, 0, 0, -5);
	//ft_sphere_set(&data.sp, center, 2);
	// ft_vec3_set_xyz(&center, 0, 0, -1);
	// ft_sphere_set(&data.sp, center, 0.5);
	data.world = object(SP, sphere(ft_vec3_set_xyz(&center, -2, 0, -5), 2)); // world 에 구1 추가
	oadd(&data.world, object(SP, sphere(ft_vec3_set_xyz(&center, 2, 0, -5), 2))); // world 에 구2 추가
	oadd(&data.world, object(SP, sphere(ft_vec3_set_xyz(&center, 0, -1000, 0), 990))); // world 에 구3 추가
	data.mlx = mlx_init();
	//data.width = 600;
	//data.height = 400;
	aspect_ratio = 16.0 / 9.0;
	data.width = 400;
	data.height = data.width / aspect_ratio;
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenth, &data.endian);
	// ft_camera_set(&data.cam, data.width / data.height);
	ft_camera_set(&data.cam, aspect_ratio);
	printf("aspect_ratio : %f, data.width / data.height : %d\n",aspect_ratio, data.width / data.height);
	// printf("aspect_ratio : %f, data.width / data.height : %f\n",aspect_ratio, (float)data.width / (float)data.height);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
