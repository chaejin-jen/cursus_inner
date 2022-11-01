#ifndef OBJECT_H
# define OBJECT_H

# include "rt_int.h"

t_object	*create_object(t_object_type type, void *element, const t_color3 *albedo);
t_light		*create_light(const t_point3 *light_origin, const t_color3 *light_color, double bright_ratio);
t_sphere	*create_sphere(const t_point3 *center, double radius);

void		oadd(t_object **list, t_object *new);
t_object	*olast(t_object *list);


#endif
