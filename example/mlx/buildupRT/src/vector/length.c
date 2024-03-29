#include "vec3.h"
#include <math.h>
#include <stdlib.h>

double	vec_norm(const t_vec3 *v1)
{
	return (sqrt(vec_norm_squared(v1)));
}

double	vec_norm_squared(const t_vec3 *v1)
{
	return (v1->x * v1->x + v1->y * v1->y + v1->z * v1->z);
}

t_vec3	*vec_unit_vec(t_vec3 *target, const t_vec3 *v1)
{
	return (vec_div_scalar(target, vec_norm(v1), v1));
	// double len = vec_norm(v1);
	// if (len == 0)
    // {
    //     printf("Error\n:Devider is 0");
    //     exit(0);
    // }
	// return (vec_div_scalar(target, len, v1));

}

