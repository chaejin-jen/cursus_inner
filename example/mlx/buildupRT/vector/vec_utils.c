#include "vec3.h"
#include <math.h>

float	ft_vec3_norm(t_vec3 *target)
{
	return (sqrt(ft_vec3_norm_squared(target)));
}

float	ft_vec3_norm_squared(t_vec3 *target)
{
	float result;

	result = target->x * target->x
		+ target->y * target->y
		+ target->z * target->z;
	return (result);
}

t_vec3	*ft_vec3_unit_vec(t_vec3 *target, t_vec3 *v)
{
	return (ft_vec3_div_scalar(target, ft_vec3_norm(v), v));
}

t_vec3	*ft_vec3_set_vec3(t_vec3 *target, const t_vec3 *v)
{
	target->x = v->x;
	target->y = v->y;
	target->z = v->z;
	return (target);
}

t_vec3	*ft_vec3_set_xyz(t_vec3 *target, const float x, const float y, const float z)
{
	target->x = x;
	target->y = y;
	target->z = z;
	return (target);
}

// t_vec3 *unit_vector(t_vec3 v)
// {
// 	t_vec3	
// 	return v / v.ft_vec3_norm(&v);
// }
