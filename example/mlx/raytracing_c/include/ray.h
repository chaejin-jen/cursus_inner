#ifndef RAY_H
# define RAY_H

# include "rt_int.h"

t_ray		ray_primary(const t_camera *cam, float t1, float t2);
t_ray		ray_set(const t_point3 *origin, const t_vec3 *direction);
t_point3	ray_at(const t_ray *ray, float t);
t_color3	ray_color(t_scene *scene);

t_color3	phong_lighting(const t_scene *scene);

void		record_init(t_hit_record *rec);
void		record_set_face_normal(t_ray *r, t_hit_record *rec);

t_bool		hit(t_object *object, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *object, t_ray *ray, t_hit_record *rec);

t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec);
t_bool	    hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec);

#endif
