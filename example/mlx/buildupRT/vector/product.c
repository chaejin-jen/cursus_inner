#include "vec3.h"

float	ft_vec3_dot(t_vec3 *u, t_vec3 *v)
{
	return (u->x * v->x + u->y * v->y + u->z * v->z);
}

t_vec3	*ft_vec3_cross(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
	target->x = u->y * v->z - u->z * v->y;
	target->y = u->z * v->x - u->x * v->z;
	target->z = u->x * v->y - u->y * v->x;
	return (target);
}