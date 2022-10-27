#ifndef OBJECT_H
# define OBJECT_H

# include "ray.h"

typedef int	t_object_type;
# define SP 0

typedef struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
}				t_object;

typedef struct  s_sphere
{
	t_point3	center;
	double		radius;
	double		radius_squared;
}	t_sphere;

void		ft_sphere_set(t_sphere *sp, t_point3 center, double radius);
// t_color3	ray_color(t_ray *ray, t_object *world);

// trace/hit/
t_bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);

// t_object	*object(t_object_type type, void *element);
t_object	*object(t_object_type type, void *element, t_color3 *albedo)
t_sphere	*sphere(t_point3 *center, double radius);
// t_sphere	*sphere(t_point3 center, double radius);

void		oadd(t_object **list, t_object *new);
t_object	*olast(t_object *list);

#endif
