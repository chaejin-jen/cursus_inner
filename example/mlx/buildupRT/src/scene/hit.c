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
	return (hit_result);
}