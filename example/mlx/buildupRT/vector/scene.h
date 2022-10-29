#ifndef SCENE_H
# define SCENE_H

# include "ray.h"
# include "object.h"

// typedef int t_object_type;
# define LIGHT_POINT 1
# define EPSILON 1e-6 // 0.000001

typedef struct	s_camera
{
	t_point3	orig;	// 카메라 원점(위치)
	double		viewport_h; // 뷰포트 세로길이
	double		viewport_w; // 뷰포트 가로길이
	t_vec3		horizontal; // 수평길이 벡터
	t_vec3		vertical; // 수직길이 벡터
	double		focal_len; // focal length
	t_point3	lower_left_corner; // 왼쪽 아래 코너점
}				t_camera;

typedef struct	s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}				t_canvas;

typedef struct		s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
}				t_light;

typedef struct	s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient; // 반사율
	t_ray			ray;
	t_hit_record	rec;
}				t_scene;

t_scene	*scene_init(int width, int height);

void	ft_canvas_set(t_canvas *canvas, int width, int height);
void	ft_camera_set(t_camera *cam, t_canvas *canvas, t_point3 *orig);
t_ray	*ft_camera_cal_ray(t_ray *target, t_camera *cam,
							double u, double v);

t_light	*light_point(t_point3 *light_origin, t_color3 *light_color, double bright_ratio);


#endif
