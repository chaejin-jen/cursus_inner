#ifndef RAY_H
# define RAY_H

#include "vec3.h"

typedef struct	s_ray
{
	t_point3	orig; // origin
	t_vec3		dir;  // direction
}		t_ray;

//sphere00 hit 여부
//sphere02 origin과 교점 사이의 거리
//hist_record 광원이 오브젝트에 미치는 영향을 계산 (교점에서의 법선 벡터 필요 <- 교점의 정확한 위치 필요)
typedef struct s_hit_record
{
	t_point3	p; // 교점의 좌표
	t_vec3		normal; // 교점에서의 법선
	double		t; // 광선의 원점과 교점 사이의 거리
	double		tmin;
	double		tmax;
	t_bool		front_face;
	// 그 외 교점에서의 색깔 등 추가적으로 필요한 정보는 이후에 추가
	t_color3	albedo;  // 반사율
}			t_hit_record;


t_ray		*ft_ray_set(t_ray *target, const t_point3 *origin, const t_vec3 *direction);
t_point3	*ft_ray_at(t_point3 *target, const t_ray *ray, const double t);

t_hit_record *record_init(t_hit_record *record);
void	ft_hit_record_set_face_normal(t_ray *r, t_hit_record *rec);

#endif
