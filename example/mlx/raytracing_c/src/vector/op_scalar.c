#include "vec3.h"

t_vec3	ft_vec3_add_scalar(t_vec3 v1, const double t)
{
	v1.x += t;
	v1.y += t;
	v1.z += t;
	return (v1);
}

t_vec3	ft_vec3_sub_scalar(t_vec3 v1, const double t)
{
	v1.x -= t;
	v1.y -= t;
	v1.z -= t;
	return (v1);
}


t_vec3	ft_vec3_multi_scalar(t_vec3 v1, const double t)
{
	v1.x *= t;
	v1.y *= t;
	v1.z *= t;
	return (v1);
}

t_vec3	ft_vec3_div_scalar(t_vec3 v1, const double t)
{
	return (ft_vec3_multi_scalar(v1, (1 / t)));
}
