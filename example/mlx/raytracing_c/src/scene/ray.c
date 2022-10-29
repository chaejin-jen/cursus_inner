#include "ray.h"
#include <math.h>

t_ray	ft_camera_cal_ray(const t_camera *cam, const double t1, const double t2)
{
	t_vec3	cal; // left_bottom + t1 * horizontal + t2 * t2ertical - origin 의 단위 벡터.

	cal.x = cam->lower_left_corner.x
			+ t1 * cam->horizontal.x
			+ t2 * cam->vertical.x
			- cam->orig.x;
	cal.y = cam->lower_left_corner.y
			+ t1 * cam->horizontal.y
			+ t2 * cam->vertical.y
			- cam->orig.y;
	cal.z = cam->lower_left_corner.z
			+ t1 * cam->horizontal.z
			+ t2 * cam->vertical.z
			- cam->orig.z;
	return (ft_ray_set(&(cam->orig), &cal));
}

// 광선 방향은 단위 길이 벡터가 아님에 유의 (속도적 측면 고려한 것)
t_ray	ft_ray_set(const t_point3 *origin, const t_vec3 *direction)
{
	t_ray ray;

	ray.orig = *origin;
	ray.dir = ft_vec3_unit(*direction);
	return (ray);
}

// target은 ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점이 됨
t_point3	ft_ray_at(const t_ray *ray, const double t)
{
	t_point3 p;

	p.x = ray->orig.x + t * ray->dir.x;
	p.y = ray->orig.y + t * ray->dir.y;
	p.z = ray->orig.z + t * ray->dir.z;
	return (p);
}

// 레이트레이싱을 통해 픽셀의 색깔을 결정
t_color3	ft_ray_color(t_scene *scene)
{
	double		t;
	t_color3	cal1;
	t_color3	cal2;
	t_vec3		n; // [-1, 1] 로 정규화된 법선 -> [0, 1]

	record_init(&scene->rec);
	if (hit(scene->object, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	t = 0.5 * (scene->ray.dir.y + 1.0);
	// (1-t) * 흰색 + t * 하늘색
	cal1 = ft_vec3_multi_scalar(ft_vec3_set(1.0, 1.0, 1.0), 1.0 - t);
	cal2 = ft_vec3_multi_scalar(ft_vec3_set(0.5, 0.7, 1.0), t);
	return (ft_vec3_add(cal1, cal2));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;
	t_color3	white;
	t_color3	cal;

	light_color = ft_vec3_set(0, 0, 0); //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
	lights = scene->light;
	 while (lights) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
	 {
	 	if(lights->type == LIGHT)
		{
			cal = point_light_get(scene, lights->element);
	 		light_color = ft_vec3_add(light_color, cal);
		}
	 	lights = lights->next;
	 }
	light_color = ft_vec3_add(light_color, scene->ambient);
	white = ft_vec3_set(1, 1, 1);
	cal = ft_vec3_multi(light_color, scene->rec.albedo);
	return (ft_vec3_min(cal, white));
	//모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd; // diffuse의 강도
	t_vec3		tmp;

	tmp = ft_vec3_sub(light->orig, scene->rec.p);
	light_dir = ft_vec3_unit(tmp); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	// cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
	kd = fmax(ft_vec3_dot(scene->rec.normal, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
	diffuse = ft_vec3_multi_scalar(light->light_color, kd);
	return (diffuse);
}