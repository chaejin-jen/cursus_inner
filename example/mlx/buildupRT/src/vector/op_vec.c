#include "vec3.h"

t_vec3	*vec_add(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2)
{
	target->x = v1->x + v2->x;
	target->y = v1->y + v2->y;
	target->z = v1->z + v2->z;
	return (target);
}

t_vec3	*vec_sub(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2)
{
	target->x = v1->x - v2->x;
	target->y = v1->y - v2->y;
	target->z = v1->z - v2->z;
	return (target);
}

t_vec3	*vec_mul(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2)
{
	target->x = v1->x * v2->x;
	target->y = v1->y * v2->y;
	target->z = v1->z * v2->z;
	return (target);
}

t_vec3	*vec_div(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2)
{
	target->x = v1->x / v2->x;
	target->y = v1->y / v2->y;
	target->z = v1->z / v2->z;
	return (target);
}
