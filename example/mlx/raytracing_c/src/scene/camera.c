#include "scene.h"

void	ft_camera_set(t_camera *cam, double aspect_ratio, t_point3 orig)
{
	cam->viewport_h = 2.0;
	cam->viewport_w = cam->viewport_h * aspect_ratio;
	cam->lens_radius = 1.0;
	cam->orig = orig;
	cam->horizontal = ft_vec3_set(cam->viewport_w, 0.0, 0.0);
	cam->vertical = ft_vec3_set(0.0, cam->viewport_h, 0.0);
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