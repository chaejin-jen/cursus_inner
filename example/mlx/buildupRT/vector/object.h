#ifndef OBJECT_H
# define OBJECT_H

# include "vec3.h"

typedef struct  s_sphere
{
	t_point3	center;
	double		radius;
	double		radius_squared;
}	t_sphere;

void	ft_sphere_set(t_sphere *sp, t_point3 center, double radius);

#endif
