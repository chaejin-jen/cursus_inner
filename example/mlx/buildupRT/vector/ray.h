#ifndef RAY_H
# define RAY_H

#include "vec3.h"

typedef struct	s_ray
{
	t_point3	orig; // origin
	t_vec3		dir;  // direction
}		t_ray;

t_ray		*ft_ray_set(t_ray *target, const t_point3 *origin, const t_vec3 *direction);
t_point3	*ft_ray_at(t_point3 *target, const t_ray *ray, const float t);

#endif