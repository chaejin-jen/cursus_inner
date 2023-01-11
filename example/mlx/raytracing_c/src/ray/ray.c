#include "ray.h"
#include <math.h>

t_ray	ray_primary(const t_camera *cam, float u, float v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vunit(vsub_(vadd_(vadd_(cam->lower_left_corner, vmul(cam->horizontal, u)), vmul(cam->vertical, v)), cam->orig));
	return (ray);
	// t_vec3	cal; // left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.

	// cal.x = cam->lower_left_corner.x
	// 		+ u * cam->horizontal.x
	// 		+ v * cam->vertical.x
	// 		- cam->orig.x;
	// cal.y = cam->lower_left_corner.y
	// 		+ u * cam->horizontal.y
	// 		+ v * cam->vertical.y
	// 		- cam->orig.y;
	// cal.z = cam->lower_left_corner.z
	// 		+ u * cam->horizontal.z
	// 		+ v * cam->vertical.z
	// 		- cam->orig.z;
	// return (ray_set(&(cam->orig), &cal));
	// t_ray	ray;
	// ray.orig = cam->orig;
	// ray.dir = vunit(cal);
	// return (ray);
}

// 광선 방향은 단위 길이 벡터가 아님에 유의 (속도적 측면 고려한 것)
t_ray	ray_set(const t_point3 *origin, const t_vec3 *direction)
{
	t_ray ray;

	ray.orig = *origin;
	ray.dir = vunit(*direction);
	// vprnt("pram direction", direction);
	// vprnt("ray.dir", &ray.dir);
	return (ray);
}

// target은 ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점이 됨
t_point3	ray_at(const t_ray *ray, float t)
{
	t_point3 p;

	// p = vadd_(ray->orig, vmul(ray->dir, t));
	p.x = ray->orig.x + t * ray->dir.x;
	p.y = ray->orig.y + t * ray->dir.y;
	p.z = ray->orig.z + t * ray->dir.z;
	return (p);
}

// 레이트레이싱을 통해 픽셀의 색깔을 결정
t_color3	ray_color(t_scene *scene)
{
	float		t;

	record_init(&scene->rec);
	if (hit(scene->object, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	t = 0.5 * (scene->ray.dir.y + 1.0);
	// (1-t) * 흰색 + t * 하늘색
	return (vadd_(vmul(color3(1.0, 1.0, 1.0), 1.0 - t), vmul(color3(0.5, 0.7, 1.0), t)));
}
