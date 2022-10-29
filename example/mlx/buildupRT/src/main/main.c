//sphere02_phong_lighting
// 퐁 조명 모델의 광선 추적 : 광원에서 빛이 나와서 물체에 반사되어 눈에 들어오는 단계만 수학적으로 계산
// 퐁 반사 모델 : (물리학적 기법) 광원에서 나온 빛이 물체에 반사되어 나올 때, 그 조도가 어느 정도가 되는지를 구하는 데에 활용되는 모델
// 퐁 반사 모델의 조명(3가지) : (조도를 구할 때 고려하는 조명) ambient lighting, diffuse lighting, specular lighting
// ambient lighting(주변 조명) : 밝은 낮 어두운 그늘에 들어가도 물체가 보이는 것처럼, 공기 중에 산란되어 존재하는 빛으로 인해 물체가 밝아지는 것을 묘사함
// diffuse lighting(확산 조명) : 난반사의 역할 - 광선이 물체에 비스듬하게 들어올 수록 단위 면적 당 들어오는 광선의 수가 적음
// specular lighting(반사광) : 정반사의 역할
// #include "mlx.h"
#include <mlx.h>
#include "libft.h"
#include "ray.h"
#include "scene.h"
#include "object.h"
#include <math.h>

#include <stdio.h>
#include <string.h>

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
	t_color3	color;
	t_scene		*scene;

	scene = data->scene;
	j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		ft_putstr_fd("\rScanlines remaining: ", 1);
		ft_putnbr_fd(j, 1);
		ft_putchar_fd(' ', 1);
		while (i < scene->canvas.width)
		{
			ft_camera_cal_ray(&scene->ray, &scene->camera, (double)i / (scene->canvas.width - 1),
				(double)j / (scene->canvas.height - 1));
			ft_ray_color(&color, scene);
			vec_mul_scalar(&color, 255.999, &color);
			my_mlx_pixel_put(data, i, scene->canvas.height - 1 - j, &color);
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

void set_width_height(t_bool is_default, int *width, int *height, char **av)
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
