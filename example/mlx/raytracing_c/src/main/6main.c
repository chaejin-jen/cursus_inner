#include <mlx.h>
#include "scene.h"
#include "ray.h"
#include "object.h"
#include "libft.h" // atoi
#include "math.h"

static void set_width_height(t_bool is_default, int *width, int *height, char **av);
static void rt_data_init(t_rt_data *data, int width, int height);
static void	my_mlx_pixel_put(t_img *img, int x, int y, t_color3 *color);
static int ft_draw(t_rt_data *data);
static int main_loop(t_rt_data *data);

int	main(int argc, char *argv[])
{
	int			width;
	int			height;
	t_rt_data	data;

	set_width_height(argc!=3, &width, &height, argv);
	data.scene = scene_init(width, height);
	rt_data_init(&data, width, height);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}

static void set_width_height(t_bool is_default, int *width, int *height, char **av)
{
	if (!is_default)
	{
		*width = ft_atoi(av[1]);
		*height = ft_atoi(av[2]);
	}
	if (is_default || !*width || !*height)
	{
		*width = 400;
		*height = 300;
	}
}

static void rt_data_init(t_rt_data *data, int width, int height)
{
	double		aspect_ratio;

	//printf("P3\n%d %d\n255\n", data->scene->canvas.width, data->scene->canvas.height);
	data->mlx = mlx_init();
	aspect_ratio = 16.0 / 9.0;
	data->width = width;
	data->height = data->width / aspect_ratio;
	data->mlx_win = mlx_new_window(data->mlx, data->width, data->height, "miniRT");
	data->img.ptr = mlx_new_image(data->mlx, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.ptr,
		&data->img.bits_per_pixel, &data->img.line_lenth, &data->img.endian);
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, t_color3 *color)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_lenth + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = ((int)color->x << 16) | ((int)color->y << 8) | (int)color->z;
}

t_color3	*old_ray_color(t_color3 *target, t_ray *r, t_object *world)
{
	t_vec3			unit_dir;
	double			t;
	t_color3		cal1;
	t_color3		cal2;
	t_vec3			n; // [-1, 1] 로 정규화된 법선 -> [0, 1]
	t_hit_record	rec;
	t_vec3			tmp;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	if (hit(world, r, &rec))
	{
		*target = rec.normal;
		*target = ft_vec3_multi_scalar(ft_vec3_add_scalar(*target, 1), 0.5);
		return (target);
	}
	unit_dir = ft_vec3_unit(r->dir);
	t = 0.5 * (unit_dir.y + 1.0);
	 // (1-t) * 흰색 + t * 하늘색
	cal1 = ft_vec3_set(1.0, 1.0, 1.0);
	cal1 = ft_vec3_multi_scalar(cal1, (1.0 - t));
	cal2 = ft_vec3_set(1.0, 1.0, 1.0);
	cal2 = ft_vec3_multi_scalar(cal2, t);
	*target = ft_vec3_add(cal1, cal2);
	return (target);
}

static int ft_draw(t_rt_data *data)
{
	int			i;
	int			j;
	t_ray		ray;
	t_color3		color;
	t_scene		*scene;

	scene = data->scene;
	j = data->height - 1;
	while (j >= 0)
	{
		i = 0;
		ft_putstr_fd("\rScanlines remaining: ", 1);
		ft_putnbr_fd(j, 1);
		ft_putchar_fd(' ', 1);
		while (i < data->width)
		{
			scene->ray = ft_camera_cal_ray(&scene->camera, (double)i / (data->width - 1), (double)j / (data->height - 1));
			//color = ft_ray_color(scene);
			old_ray_color(&color, &scene->ray, scene->object);
			color = ft_vec3_multi_scalar(color, 255.999);
			my_mlx_pixel_put(&data->img, i, data->height - 1 - j, &color);
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.ptr, 0, 0);
	return (0);
}

static int main_loop(t_rt_data *data)
{
	ft_draw(data);
	return (0);
}
