#include "scene.h"
#include "ray.h"
#include "object.h"
#include <unistd.h>
#include <stdlib.h>

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka; // 8.4 에서 설명
	t_point3	orig;
	t_color3	color;
	t_vec3		vec3;
	t_point3	center;

	// malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	ft_canvas_set(&scene->canvas, 400, 300);
	ft_camera_set(&scene->camera, &scene->canvas, (t_point3 *)ft_vec3_set_xyz(&vec3, 0, 0, 0));
	world = object(SP, sphere(ft_vec3_set_xyz(&center, -2, 0, -5), 2), (t_color3 *)ft_vec3_set_xyz(&vec3, 0.5, 0, 0)); // world 에 구1 추가
	oadd(&world, object(SP, sphere(ft_vec3_set_xyz(&center, 2, 0, -5), 2), (t_color3 *)ft_vec3_set_xyz(&vec3, 0, 0.5, 0))); // world 에 구2 추가
	oadd(&world, object(SP, sphere(ft_vec3_set_xyz(&center, 0, -1000, 0), 990), (t_color3 *)ft_vec3_set_xyz(&vec3, 1, 1, 1))); // world 에 구3 추가
	scene->world = world;
	//printf("(scene_init)sp radius : %f, %f, %f\n", ((t_sphere *)world->element)->radius, ((t_sphere *)((t_object *)world->next)->element)->radius, ((t_sphere *)((t_object *)((t_object *)world->next)->next)->element)->radius);
	lights = object(LIGHT_POINT,
		(void *)light_point(ft_vec3_set_xyz(&orig, 0, 5, 0), ft_vec3_set_xyz(&vec3, 1, 1, 1), 0.5),
		ft_vec3_set_xyz(&color, 0, 0, 0)); // 더미 albedo
	scene->light = lights;
	//printf("(scene_init)light bright_ratio : %f\norigin : %f, %f, %f\nlight_color: %f, %f, %f\n",
	//	((t_light *)scene->light->element)->bright_ratio,
	//	((t_light *)scene->light->element)->origin.x, ((t_light *)scene->light->element)->origin.y, ((t_light *)scene->light->element)->origin.z,
	//	((t_light *)scene->light->element)->light_color.x, ((t_light *)scene->light->element)->light_color.y, ((t_light *)scene->light->element)->light_color.z);
	ka = 0.1; // 8.4 에서 설명
	scene->ambient = *ft_vec3_multi_scalar(&vec3, ka, ft_vec3_set_xyz(&vec3, 1, 1, 1)); // 반사율
	//ft_vec3_set_vec3(&scene->ambient, ft_vec3_multi_scalar(&vec3, ka, ft_vec3_set_xyz(&vec3, 1, 1, 1))); // 반사율
	//printf("(scene_init)ambient : %f, %f, %f\n", scene->ambient.x, scene->ambient.y, scene->ambient.z);
	return (scene);
}

t_light	*light_point(t_point3 *light_origin, t_color3 *light_color, double bright_ratio)
{
	t_light	*light;

	if(!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = *light_origin;
	light->light_color = *light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}

void	ft_canvas_set(t_canvas *canvas, int width, int height)
{
	canvas->width = width;
	canvas->height = height;
	canvas->aspect_ratio = (double)width / (double)height;
}

void	ft_camera_set(t_camera *cam, t_canvas *canvas, t_point3 *orig)
{
	t_vec3	focal_len;

	cam->viewport_h = 2.0;
	cam->viewport_w = cam->viewport_h * canvas->aspect_ratio;
	cam->focal_len = 1.0;
	cam->orig = *orig;
	//ft_vec3_set_xyz(&cam->orig, 0.0, 0.0, 0.0);
	ft_vec3_set_xyz(&cam->horizontal, cam->viewport_w, 0.0, 0.0);
	ft_vec3_set_xyz(&cam->vertical, 0.0, cam->viewport_h, 0.0);
	//cam->lower_left_corner.x = cam->orig.x
	//			- (cam->horizontal.x / 2)
	//			- (cam->vertical.x / 2) - 0;
	//cam->lower_left_corner.y = cam->orig.y
	//			- (cam->horizontal.y / 2)
	//			- (cam->vertical.y / 2) - 0;
	//cam->lower_left_corner.z = cam->orig.z
	//			- (cam->horizontal.z / 2)
	//			- (cam->vertical.z / 2)
	//			- cam->focal_len;
	ft_vec3_set_xyz(&focal_len, 0, 0, cam->focal_len);
	ft_vec3_add(&cam->lower_left_corner, &cam->horizontal, &cam->vertical);
	ft_vec3_div_scalar(&cam->lower_left_corner, 2, &cam->lower_left_corner);
	ft_vec3_add(&cam->lower_left_corner, &cam->lower_left_corner, &focal_len);
	ft_vec3_sub(&cam->lower_left_corner, &cam->orig, &cam->lower_left_corner);
}

// 카메라에서 출발한 광선
t_ray	*ft_camera_cal_ray(t_ray *target, t_camera *cam,
							 double u, double v)
{
	t_vec3 cal; // left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.

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
