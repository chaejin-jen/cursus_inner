#ifndef VEC3_H
# define VEC3_H

# include <stdio.h> //printf

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef t_vec3 t_point3;

t_vec3	ft_vec3_set(const double x, const double y, const double z);
t_vec3	ft_vec3_min(const t_vec3 v1, const t_vec3 v2);

t_vec3	ft_vec3_add(t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_sub(t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_multi(t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_div(t_vec3 v1, const t_vec3 v2);

t_vec3	ft_vec3_add_scalar(t_vec3 v1, const double t);
t_vec3	ft_vec3_sub_scalar(t_vec3 v1, const double t);
t_vec3	ft_vec3_multi_scalar(t_vec3 v1, const double t);
t_vec3	ft_vec3_div_scalar(t_vec3 v1, const double t);

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
double	ft_vec3_dot(const t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_cross(const t_vec3 v1, const t_vec3 v2);

/* 벡터의 길이 */
double	ft_vec3_norm_squared(const t_vec3 v);
double	ft_vec3_norm(const t_vec3 v);
t_vec3	ft_vec3_unit(const t_vec3 v1);


#endif
