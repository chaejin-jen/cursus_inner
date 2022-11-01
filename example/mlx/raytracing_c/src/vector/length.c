#include "vec3.h"
#include <math.h>

double	vnorm_squared(const t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vnorm(const t_vec3 v)
{
	return (sqrt(vnorm2(v)));
}


t_vec3	vunit(const t_vec3 v1)
{
	t_vec3	v;
	return (vdiv(v, vnorm(v1)));
}
