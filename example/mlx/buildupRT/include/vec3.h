#ifndef VEC3_H
# define VEC3_H

#include <stdio.h> //printf

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

//t_vec3	*vec_set_vec3(t_vec3 *target, const t_vec3 *v);
t_vec3	*vec_set(t_vec3 *target, double x, double y, double z);
t_vec3	*vec_min(t_vec3 *target, const t_vec3 *vec1, const t_vec3 *vec2);

t_vec3	*vec_add(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2);
t_vec3	*vec_sub(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2);
t_vec3	*vec_mul(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2);
t_vec3	*vec_div(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2);

t_vec3	*vec_add_scalar(t_vec3 *target, double t, const t_vec3 *v1);
t_vec3	*vec_sub_scalar(t_vec3 *target, double t, const t_vec3 *v1);
t_vec3	*vec_mul_scalar(t_vec3 *target, double t, const t_vec3 *v1);
t_vec3	*vec_div_scalar(t_vec3 *target, double t, const t_vec3 *v1);

/* 벡터곱 연산 결과
	행벡터 곱하기 열벡터 -> 스칼라
	열벡터 곱하기 행백터 -> 행렬
	행렬 곱하기 열벡터 -> 벡터
	똑같은 벡터의 내적 -> 벡터의 놈 -> 제곱합 -> 스칼라
*/
/* inner product 방향이 일치하는 만큼만 곱한 것 (결과값은 스칼라)
두 벡터의 차원(길이)은 같아야 함
앞은 행 벡터, 뒤는 열 벡터가 와야 함 x^{T}y
*/
double	vec_dot(const t_vec3 *v1, const t_vec3 *v2);
t_vec3	*vec_cross(t_vec3 *target, const t_vec3 *v1, const t_vec3 *v2);

double	vec_norm(const t_vec3 *v1);
double	vec_norm_squared(const t_vec3 *v1);
t_vec3	*vec_unit_vec(t_vec3 *target, const t_vec3 *v1);


#endif
