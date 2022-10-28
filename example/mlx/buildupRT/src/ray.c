#include "ray.h"
#include "scene.h"
#include "math.h"

// 광선 방향은 단위 길이 벡터가 아님에 유의 (속도적 측면 고려한 것)
t_ray	*ft_ray_set(t_ray *target, const t_point3 *origin, const t_vec3 *direction)
{
	target->orig = *origin; // ft_vec3_set_vec3(&target->orig, origin);
	target->dir = *direction; // ft_vec3_set_vec3(&target->dir, direction);
	return (target);
}

// target은 ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점이 됨
t_point3	*ft_ray_at(t_point3 *target, const t_ray *ray, const double t)
{
	target->x = ray->orig.x + t * ray->dir.x;
	target->y = ray->orig.y + t * ray->dir.y;
	target->z = ray->orig.z + t * ray->dir.z;
	return (target);
}

t_hit_record *record_init(t_hit_record *target)
{
	target->tmin = EPSILON;
	target->tmax = INFINITY;
	return (target);
}

void	ft_hit_record_set_face_normal(t_ray *r, t_hit_record *rec)
{
	// 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
	rec->front_face = ft_vec3_dot(&r->dir, &rec->normal) < 0;
	// 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
	if (!rec->front_face)
		ft_vec3_multi_scalar(&rec->normal, -1, &rec->normal);
}
