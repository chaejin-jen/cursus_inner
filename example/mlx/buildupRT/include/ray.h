#ifndef RAY_H
# define RAY_H

# include "rt_int.h"

t_ray		ft_camera_cal_ray(const t_camera *cam, const double t1, const double t2);
t_ray		ft_ray_set(const t_point3 *origin, const t_vec3 *direction);
t_point3	ft_ray_at(const t_ray *ray, const double t);
t_color3	ft_ray_color(t_scene *scene);
t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);

void		record_init(t_hit_record *rec);
void		record_set_face_normal(t_ray *r, t_hit_record *rec);

t_bool		hit(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *world, t_ray *ray, t_hit_record *rec);

t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec);

#endif
