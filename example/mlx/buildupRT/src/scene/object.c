#include "object.h"
#include <stdlib.h>

t_object	*create_object(t_object_type type, void *element, t_color3 *albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = *albedo;
	//new->object_handler = 
	return (new);
}

t_light	*create_light(t_point3 *light_origin, t_color3 *light_color, double bright_ratio)
{
	t_light	*light;

	if(!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->orig = *light_origin;
	light->light_color = *light_color;
	//printf("(light) origin : %f, %f, %f, color : %f, %f, %f\n", light->orig.x, light->orig.y, light->orig.z, light->light_color.x, light->light_color.y, light->light_color.z);
	light->bright_ratio = bright_ratio;
	return (light);
}

//void	ft_sphere_set(t_sphere *sp, t_point3 center, double radius)
//{
//	sp->center = center;
//	sp->radius = radius;
//	sp->radius_squared = radius * radius;
//}

t_sphere	*create_sphere(t_point3 *center, double radius)
{
	t_sphere *sp;

	if(!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = *center;
	sp->radius = radius;
	sp->radius_squared = radius * radius;
	return (sp);
}

void	oadd(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_object	*olast(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}