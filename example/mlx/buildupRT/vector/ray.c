#include "ray.h"

t_ray	*ft_ray_set(t_ray *target, const t_point3 *origin, const t_vec3 *direction)
{
	target->orig = *origin; // ft_vec3_set_vec3(&target->orig, origin);
	target->dir = *direction; // ft_vec3_set_vec3(&target->dir, direction);
	return (target);
}


t_point3	*ft_ray_at(t_point3 *target, const t_ray *ray, const float t)
{
	target->x = ray->orig.x + t * ray->dir.x;
	target->y = ray->orig.y + t * ray->dir.y;
	target->z = ray->orig.z + t * ray->dir.z;
	return (target);
}