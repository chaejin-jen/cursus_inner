#ifndef RAY_H
# define RAY_H

# include "rt_int.h"

t_ray		*ft_camera_cal_ray(t_ray *target, const t_camera *cam, const double t1, const double t2);
t_ray		*ft_ray_set(t_ray *target, const t_point3 *origin, const t_vec3 *direction);
t_point3	*ft_ray_at(t_point3 *target, const t_ray *ray, const double t);
t_color3	*ft_ray_color(t_color3 *target, t_scene *scene);
// t_color3	*phong_lighting(t_color3 *target, const t_scene *scene);
// t_color3	*point_light_get(t_color3 *target, t_scene *scene, const t_light *light);

t_hit_record *record_init(t_hit_record *target);
void		record_set_face_normal(t_ray *r, t_hit_record *rec);

t_bool		hit(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *world, t_ray *ray, t_hit_record *rec);

t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec);

#endif
