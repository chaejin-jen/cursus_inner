#include "ray.h"

t_bool	hit(t_object *object, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
	hit_anything = FALSE;
	while(object)
	{
		if (hit_obj(object, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		object = object->next;
	}
	return (hit_anything);
}

t_bool	hit_obj(t_object *object, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (object->type == SP)
		hit_result = hit_sphere(object, ray, rec);
	else if (object->type == PL)
		hit_result = hit_plane(object, ray, rec);
	return (hit_result);
}

// void	record_set_face_normal(t_ray *r, t_hit_record *rec)
// {
// 	//광선의 방향벡터와 교점의 법선 벡터의 내적이 음수이면 광선은 앞면에 hit한 것 ...?
// 	rec->front_face = vdot(r->dir, rec->normal) < 0;
// 	//광선의 앞면에 hit? if so 그대로, 아니면 법선을 반대로 뒤집음(for 항상 광선방향 벡터와 법선 벡터를 반대인 상태로 사용)
// 	rec->normal = (rec->front_face) ? rec->normal : vmult(rec->normal, -1);
// }
