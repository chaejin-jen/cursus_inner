#include "object.h"

void	ft_sphere_set(t_sphere *sp, t_point3 center, double radius)
{
	sp->center = center;
	sp->radius = radius;
	sp->radius_squared = radius * radius;
}
