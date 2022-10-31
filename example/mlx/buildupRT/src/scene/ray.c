#include "ray.h"
#include <math.h>

t_ray	*ft_camera_cal_ray(t_ray *target, const t_camera *cam,
							const double u, const double v)
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

// 광선 방향은 단위 길이 벡터가 아님에 유의 (속도적 측면 고려한 것)
t_ray	*ft_ray_set(t_ray *target, const t_point3 *origin, const t_vec3 *direction)
{
	target->orig = *origin;
	vec_unit_vec(&target->dir, direction);
	return (target);
}

// target은 ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점이 됨
t_point3	*ft_ray_at(t_point3 *target, const t_ray *ray, const double t)
{
	target->x = ray->orig.x + t * ray->dir.x;
	target->y = ray->orig.y + t * ray->dir.y;
	target->z = ray->orig.z + t * ray->dir.z;
	return (target);
}

// 레이트레이싱을 통해 픽셀의 색깔을 결정
t_color3	*ft_ray_color(t_color3 *target, t_scene *scene)
{
	double		t;
	t_color3	cal1;
	t_color3	cal2;
	t_vec3		n; // [-1, 1] 로 정규화된 법선 -> [0, 1]

	record_init(&scene->rec);
	if (hit(scene->object, &scene->ray, &scene->rec))
		return (phong_lighting(target, scene)); //phong_lighting 함수는 8.4에서 설명한다. 이제 법선 벡터를 매핑해서 얻은 색이 아닌, 앞으로 작성할 phong_lighting 함수의 결과값을 반환한다!
	//ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
	t = 0.5 * (scene->ray.dir.y + 1.0);
	// (1-t) * 흰색 + t * 하늘색
	cal1 = *vec_mul_scalar(&cal1, 1.0 - t, vec_set(&cal1, 1.0, 1.0, 1.0));
	cal2 = *vec_mul_scalar(&cal2, t, vec_set(&cal2, 0.5, 0.7, 1.0));
	return (vec_add(target, &cal1, &cal2));
}

t_color3	*phong_lighting(t_color3 *target, t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;
	t_color3	diffuse;
	t_color3	white;

	vec_set(&light_color, 0, 0, 0); //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
	lights = scene->light;
	while (lights) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
	{
		if(lights->type == LIGHT)
		{
			point_light_get(&diffuse, scene, lights->element);
			vec_add(&light_color, &light_color, &diffuse);
		}
		lights = lights->next;
	}
	vec_set(&white, 1, 1, 1);
	vec_add(&light_color, &light_color, &scene->ambient);
	vec_mul(&light_color, &light_color, &scene->rec.albedo);
	return (vec_min(target, &white, &light_color));
	//모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
}

t_color3	*point_light_get(t_color3 *target, t_scene *scene, const t_light *light)
{
	t_vec3		light_dir;
	double		kd; // diffuse의 강도
	t_vec3		tmp;

	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	double		ksn;
	double		ks;

	vec_unit_vec(&light_dir, vec_sub(&tmp, &light->orig, &scene->rec.p)); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	//vec_sub(&tmp, &light->orig, &scene->rec.p);
	//vec_unit_vec(&light_dir, &tmp); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	// cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
	kd = fmax(vec_dot(&scene->rec.normal, &light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
	return (vec_mul_scalar(target, kd, &light->light_color));
}