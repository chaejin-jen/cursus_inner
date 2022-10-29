#include "ray.h"
#include <math.h>

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec3		oc; //방향벡터로 나타낸 구의 중심.
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	t_point3	tmp;

	rec->albedo = sp_obj->albedo;
	sp = (t_sphere *)(sp_obj->element);
	oc = ft_vec3_sub(ray->orig, sp->center);
	a = ft_vec3_norm_squared(ray->dir);
	half_b = ft_vec3_dot(oc, ray->dir);
	c = ft_vec3_norm_squared(oc) - sp->radius_squared;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0) // 판별식이 0보다 작을 때 : 실근 없을 때,
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	tmp= ft_vec3_sub(rec->p, sp->center);
	rec->normal = ft_vec3_div_scalar(tmp, sp->radius); // 정규화된 법선 벡터.
	record_set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
	return (TRUE);
}