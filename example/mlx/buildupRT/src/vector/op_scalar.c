#include "vec3.h"

t_vec3	*vec_add_scalar(t_vec3 *target, double t, const t_vec3 *v1)
{
	target->x = t + v1->x;
	target->y = t + v1->y;
	target->z = t + v1->z;
	return (target);
}

t_vec3	*vec_sub_scalar(t_vec3 *target, double t, const t_vec3 *v1)
{
	target->x = v1->x - t;
	target->y = v1->y - t;
	target->z = v1->z - t;
	return (target);
}

t_vec3	*vec_mul_scalar(t_vec3 *target, double t, const t_vec3 *v1)
{
	target->x = v1->x * t;
	target->y = v1->y * t;
	target->z = v1->z * t;
	return (target);
}

t_vec3	*vec_div_scalar(t_vec3 *target, double t, const t_vec3 *v1)
{
	target->x = v1->x * t;
	target->y = v1->y * t;
	target->z = v1->z * t;
	return (target);
}
