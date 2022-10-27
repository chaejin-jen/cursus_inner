#include "ray.h"

// 광선 방향은 단위 길이 벡터가 아님에 유의 (속도적 측면 고려한 것)
t_ray	*ft_ray_set(t_ray *target, const t_point3 *origin, const t_vec3 *direction)
{
	target->orig = *origin; // ft_vec3_set_vec3(&target->orig, origin);
	target->dir = *direction; // ft_vec3_set_vec3(&target->dir, direction);
	return (target);
}

// target은 ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점이 됨
t_point3	*ft_ray_at(t_point3 *target, const t_ray *ray, const float t)
{
	target->x = ray->orig.x + t * ray->dir.x;
	target->y = ray->orig.y + t * ray->dir.y;
	target->z = ray->orig.z + t * ray->dir.z;
	return (target);
}
