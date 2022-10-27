#include "scene.h"
#include "ray.h"

void	ft_canvas_set(t_canvas *canvas, int width, int height)
{
	canvas->width = width;
	canvas->height = height;
	canvas->aspect_ratio = (double)width / (double)height;
}

void	ft_camera_set(t_camera *cam, double aspect_ratio)
{
	t_vec3	focal_len;

	cam->viewport_h = 2.0;
	cam->viewport_w = aspect_ratio * cam->viewport_h;
	cam->focal_len = 1.0;
	ft_vec3_set_xyz(&cam->orig, 0.0, 0.0, 0.0);
	ft_vec3_set_xyz(&cam->horizontal, cam->viewport_w, 0.0, 0.0);
	ft_vec3_set_xyz(&cam->vertical, 0.0, cam->viewport_h, 0.0);
	//cam->lower_left_corner.x = cam->orig.x
	//			- (cam->horizontal.x / 2)
	//			- (cam->vertical.x / 2) - 0;
	//cam->lower_left_corner.y = cam->orig.y
	//			- (cam->horizontal.y / 2)
	//			- (cam->vertical.y / 2) - 0;
	//cam->lower_left_corner.z = cam->orig.z
	//			- (cam->horizontal.z / 2)
	//			- (cam->vertical.z / 2)
	//			- cam->focal_len;
	ft_vec3_set_xyz(&focal_len, 0, 0, cam->focal_len);
	ft_vec3_add(&cam->lower_left_corner, &cam->horizontal, &cam->vertical);
	ft_vec3_div_scalar(&cam->lower_left_corner, 2, &cam->lower_left_corner);
	ft_vec3_add(&cam->lower_left_corner, &cam->lower_left_corner, &focal_len);
	ft_vec3_sub(&cam->lower_left_corner, &cam->orig, &cam->lower_left_corner);
}

// 카메라에서 출발한 광선
t_ray	*ft_camera_cal_ray(t_ray *target, t_camera *cam,
							 double u, double v)
{
	t_vec3 cal; // left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.

	cal.x = cam->lower_left_corner.x
			+ u * cam->horizontal.x
			+ v * cam->vertical.x
			- cam->orig.x;
	cal.y = cam->lower_left_corner.y
			+ u * cam->horizontal.y
			+ v * cam->vertical.y
			- cam->orig.y;
	cal.z = cam->lower_left_corner.z
			+ u * cam->horizontal.z
			+ v * cam->vertical.z
			- cam->orig.z;
	return (ft_ray_set(target, &(cam->orig), &cal));
}
