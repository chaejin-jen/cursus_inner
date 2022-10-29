#include "vec3.h"
#include <math.h>

double	ft_vec3_norm_squared(const t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	ft_vec3_norm(const t_vec3 v)
{
	return (sqrt(ft_vec3_norm_squared(v)));
}


t_vec3	ft_vec3_unit(const t_vec3 v1)
{
	t_vec3	v;
	return (ft_vec3_div_scalar(v, ft_vec3_norm(v1)));
}
