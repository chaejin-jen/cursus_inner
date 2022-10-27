#include "ray.h"
#include "object.h"
#include <math.h>

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
	hit_anything = FALSE;
	while(world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문
t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec); //hit_sphere의 첫번째 인자도 t_sphere *에서 t_object *로 수정해주자.
	return (hit_result);
}

t_bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3	oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_point3	tmp;
	t_sphere	*sp;

	sp = (t_sphere *)(world->element);
	ft_vec3_sub(&oc, &ray->orig, &sp->center);
	a = ft_vec3_norm_squared(&ray->dir);
	half_b = ft_vec3_dot(&oc, &ray->dir);
	c = ft_vec3_norm_squared(&oc) - sp->radius_squared;
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
	ft_ray_at(&rec->p, ray, root);
	// ft_vec3_sub(&tmp, &rec->p, &sp->center);
	// ft_vec3_div_scalar(&rec->normal, sp->radius, &tmp); // 정규화된 법선 벡터.
	ft_vec3_div_scalar(&rec->normal, sp->radius, ft_vec3_sub(&rec->p, &rec->p, &sp->center)); // 정규화된 법선 벡터.
	ft_hit_record_set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
	return (TRUE);
}