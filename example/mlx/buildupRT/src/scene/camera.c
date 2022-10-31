#include "scene.h"

void	ft_camera_set(t_camera *cam, double aspect_ratio, t_point3 *orig)
{
	t_vec3	focal_len;

	cam->viewport_h = 2.0;
	cam->viewport_w = cam->viewport_h * aspect_ratio;
	cam->lens_radius = 1.0;
	cam->orig = *orig;
	//ft_vec3_set_xyz(&cam->orig, 0.0, 0.0, 0.0);
	vec_set(&cam->horizontal, cam->viewport_w, 0.0, 0.0);
	vec_set(&cam->vertical, 0.0, cam->viewport_h, 0.0);
	cam->lower_left_corner.x = cam->orig.x
				- (cam->horizontal.x / 2)
				- (cam->vertical.x / 2) - 0;
	cam->lower_left_corner.y = cam->orig.y
				- (cam->horizontal.y / 2)
				- (cam->vertical.y / 2) - 0;
	cam->lower_left_corner.z = cam->orig.z
				- (cam->horizontal.z / 2)
				- (cam->vertical.z / 2)
				- cam->lens_radius;
}