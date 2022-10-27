#include "ray.h"
#include "object.h"
#include <stdlib.h>

t_object	*object(t_object_type type, void *element, t_color3 *albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = *albedo;
	return (new);
}

t_sphere	*sphere(t_point3 *center, double radius)
{
	t_sphere *sp;

	if(!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = *center;
	sp->radius = radius;
	sp->radius_squared = radius * radius;
	return (sp);
}

