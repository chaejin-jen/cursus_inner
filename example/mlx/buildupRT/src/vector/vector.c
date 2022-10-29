#include "vec3.h"

t_vec3	*vec_set(t_vec3 *target, double x, double y, double z)
{
	target->x = x;
	target->y = y;
	target->z = z;
	return (target);
}

t_vec3	*vec_min(t_vec3 *target, t_vec3 *vec1, t_vec3 *vec2)
{
	if (vec1->x > vec2->x)
		target->x = vec2->x;
	if (vec1->y > vec2->y)
		target->y = vec2->y;
	if (vec1->z > vec2->z)
		target->z = vec2->z;
	return (target);
}
