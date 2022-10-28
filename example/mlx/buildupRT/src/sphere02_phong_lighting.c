// 퐁 조명 모델의 광선 추적 : 광원에서 빛이 나와서 물체에 반사되어 눈에 들어오는 단계만 수학적으로 계산
// 퐁 반사 모델 : (물리학적 기법) 광원에서 나온 빛이 물체에 반사되어 나올 때, 그 조도가 어느 정도가 되는지를 구하는 데에 활용되는 모델
// 퐁 반사 모델의 조명(3가지) : (조도를 구할 때 고려하는 조명) ambient lighting, diffuse lighting, specular lighting
// ambient lighting(주변 조명) : 밝은 낮 어두운 그늘에 들어가도 물체가 보이는 것처럼, 공기 중에 산란되어 존재하는 빛으로 인해 물체가 밝아지는 것을 묘사함
// diffuse lighting(확산 조명) : 난반사의 역할 - 광선이 물체에 비스듬하게 들어올 수록 단위 면적 당 들어오는 광선의 수가 적음
// specular lighting(반사광) : 정반사의 역할
#include "mlx.h"
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
	t_scene	*scene;
}						t_data;

t_color3	*point_light_get(t_color3 *target, t_scene *scene, t_light *light)
{
	//t_color3	diffuse;
	t_vec3		light_dir;
	double		kd; // diffuse의 강도
	t_vec3		tmp;

	ft_vec3_unit_vec(&light_dir, ft_vec3_sub(&tmp, &light->origin, &scene->rec.p)); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	// cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
	kd = fmax(ft_vec3_dot(&scene->rec.normal, &light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
	return (ft_vec3_multi_scalar(target, kd, &light->light_color));
}

t_color3	*phong_lighting(t_color3 *target, t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;
	t_color3	tmp;

	ft_vec3_set_xyz(&light_color, 0, 0, 0); //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
	lights = scene->light;
	//while (lights) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
	//{
	//	if(lights->type == LIGHT_POINT)
	//		ft_vec3_add(&light_color, &light_color, point_light_get(target, scene, lights->element));
	//	lights = lights->next;
	//}
	ft_vec3_add(&light_color, &light_color, &scene->ambient);
	ft_vec3_min(target, ft_vec3_multi(&light_color, &light_color, &scene->rec.albedo),
		ft_vec3_set_xyz(&tmp, 1, 1, 1));
	return (target);
	//모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
}


// 레이트레이싱을 통해 픽셀의 색깔을 결정
t_color3	*ft_ray_color(t_color3 *target, t_scene *scene)
{
	double		t;
	t_color3	cal1;
	t_color3	cal2;
	t_vec3		n;

	//광선이 구에 적중하면(광선과 구가 교점이 있고, 교점이 카메라 앞쪽이라면!)
	record_init(&scene->rec);
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(target, scene)); //phong_lighting 함수는 8.4에서 설명한다. 이제 법선 벡터를 매핑해서 얻은 색이 아닌, 앞으로 작성할 phong_lighting 함수의 결과값을 반환한다!
	else
	{
		//ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
		t = 0.5 * (scene->ray.dir.y + 1.0);
		// (1-t) * 흰색 + t * 하늘색
		ft_vec3_multi_scalar(&cal1, 1.0 - t,
			ft_vec3_set_xyz(&cal1, 1, 1, 1)),
		ft_vec3_multi_scalar(&cal2, 1.0 - t,
			ft_vec3_set_xyz(&cal2, 0.5, 0.7, 1.0));
		return (ft_vec3_add(target, &cal1, &cal2));
	}
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
			ft_vec3_multi_scalar(&color, 255.999, &color);
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

#include <stdio.h>

int main(void)
{
	t_data		data;
	double		aspect_ratio;

	data.scene = scene_init();
	printf("P3\n%d %d\n255\n", data.scene->canvas.width, data.scene->canvas.height);
	data.mlx = mlx_init();
	aspect_ratio = 16.0 / 9.0;
	data.width = 400;
	data.height = data.width / aspect_ratio;
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenth, &data.endian);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
