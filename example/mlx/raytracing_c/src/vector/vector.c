#include "vec3.h"

t_vec3	ft_vec3_set(const double x, const double y, const double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	ft_vec3_min(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3 v;

	v = v1;
	if (v1.x > v2.x)
		v.x = v2.x;
	if (v1.y > v2.y)
		v.y = v2.y;
	if (v1.z > v2.z)
		v.z = v2.z;
	return (v);
}
