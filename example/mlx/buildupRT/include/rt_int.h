#ifndef RT_INT_H
# define RT_INT_H

# include "vec3.h"
# include <stdio.h> //printf

# define EPSILON 1e-6 // 0.000001
# define LUMEN 3

typedef t_vec3 t_point3;
typedef t_vec3 t_color3;

typedef enum e_bool
{
	FALSE = 0,
	TRUE
}				t_bool;

typedef enum e_object_type
{
	CAMERA,
	AMBIENT_LIGHT,
	LIGHT,
	SP,
	PL
}				t_object_type;

typedef struct	s_camera
{
	t_point3	orig;	// 카메라 원점(위치)
	//t_point3	normal;
	t_point3	lower_left_corner; // 왼쪽 아래 코너점
	t_vec3		horizontal; // 수평길이 벡터
	t_vec3		vertical; // 수직길이 벡터
	//t_vec3		u;
	//t_vec3		v;
	//t_vec3		w;
	double		lens_radius; // focal length
	//doublevertical		time[2]; // shutter open, close times
	double		viewport_h; // 뷰포트 세로길이
	double		viewport_w; // 뷰포트 가로길이
	// TODO : viewport -> fov(Horizontal field of view in degrees in range)
	//struct t_camera	*next;
	//struct t_camera	*prev;
}				t_camera;

typedef struct		s_light
{
	t_point3	orig;
	t_color3	light_color;
	double		bright_ratio;
}				t_light;

typedef struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
	double		tm;
}				t_ray;

typedef struct s_hit_record
{
	t_point3	p; // 교점의 좌표
	t_vec3		normal; // 교점에서의 법선
	double		t; // 광선의 원점과 교점 사이의 거리
	//double		u;
	//double		v;
	double		tmin;
	double		tmax;
	t_bool		front_face;
	// 그 외 교점에서의 색깔 등 추가적으로 필요한 정보는 이후에 추가
	t_color3	albedo;  // 반사율
	//void		*mat_ptr;
}			t_hit_record;

typedef struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo; // 반사율
	void	(*object_handler)(void *element);
}				t_object;

typedef struct  s_sphere
{
	t_point3	center;
	double		radius;
	double		radius_squared;
}				t_sphere;

typedef struct	s_scene
{
	//t_canvas		canvas; // -> double	aspect_ratio;
	t_camera		camera;
	t_object		*object;
	t_object		*light;
	t_object		*ambient_light;
	t_color3		ambient; // 반사율
	t_ray			ray;
	t_hit_record	rec;
}				t_scene;

typedef struct		s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenth;
	int		endian;
}					t_img;

typedef struct 	s_rt_data
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	t_img	img;
	t_scene	*scene;
}						t_rt_data;

#endif