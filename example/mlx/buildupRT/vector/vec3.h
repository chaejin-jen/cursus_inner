#ifndef VEC3_H
# define VEC3_H

#include <stdio.h> //printf

typedef int	t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef t_vec3 t_point3; // 3D point
typedef t_vec3 t_color3; // RGB color

t_vec3	*ft_vec3_add(t_vec3 *target, t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_sub(t_vec3 *target, t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_multi(t_vec3 *target, t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_div(t_vec3 *target, t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_add_scalar(t_vec3 *target, double t, t_vec3 *v);
t_vec3	*ft_vec3_multi_scalar(t_vec3 *target, double t, t_vec3 *v);
t_vec3	*ft_vec3_div_scalar(t_vec3 *target, double t, t_vec3 *v);

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
double	ft_vec3_dot(t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_cross(t_vec3 *target, t_vec3 *u, t_vec3 *v);

/* 벡터의 길이 */
double	ft_vec3_norm(t_vec3 *v);
double	ft_vec3_norm_squared(t_vec3 *v);
t_vec3	*ft_vec3_unit_vec(t_vec3 *target, t_vec3 *v);
t_vec3	*ft_vec3_set_vec3(t_vec3 *target, const t_vec3 *v);
t_vec3	*ft_vec3_set_xyz(t_vec3 *target, double x, double y, double z);
t_vec3	*ft_vec3_min(t_vec3 *target, t_vec3 *vec1, t_vec3 *vec2);

#endif