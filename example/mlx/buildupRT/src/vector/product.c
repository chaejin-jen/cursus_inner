#include "vec3.h"

double	vec_dot(const t_vec3 *v1, const t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec3	*vec_cross(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2)
{
	target->x = v1->y * v2->z - v1->z * v2->y;
	target->y = v1->z * v2->x - v1->x * v2->z;
	target->z = v1->x * v2->y - v1->y * v2->x;
	return (target);
}
