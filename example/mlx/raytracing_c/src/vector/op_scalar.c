#include "vec3.h"

t_vec3	vadd_(t_vec3 v1, const double t)
{
	v1.x += t;
	v1.y += t;
	v1.z += t;
	return (v1);
}

t_vec3	vsub_(t_vec3 v1, const double t)
{
	v1.x -= t;
	v1.y -= t;
	v1.z -= t;
	return (v1);
}

t_vec3	vmul_(t_vec3 v1, const double t)
{
	v1.x *= t;
	v1.y *= t;
	v1.z *= t;
	return (v1);
}

t_vec3	vdiv_(t_vec3 v1, const double t)
{
	v1.x /= t;
	v1.y /= t;
	v1.z /= t;
	return (v1);
}
