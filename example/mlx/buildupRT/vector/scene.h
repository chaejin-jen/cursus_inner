#ifndef SCENE_H
# define SCENE_H

# include "ray.h"

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
	int	 width;
	int	 height;
	double	aspect_ratio;
}			t_canvas;

void	ft_canvas_set(t_canvas *canvas, int width, int height);
void	ft_camera_set(t_camera *cam, double aspect_ratio);
t_ray	*ft_camera_cal_ray(t_ray *target, t_camera *cam,
							double u, double v);

#endif
