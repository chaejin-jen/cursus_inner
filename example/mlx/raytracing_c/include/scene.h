#ifndef SCENE_H
# define SCENE_H

# include "rt_int.h"

t_scene		*scene_init(int width, int height);
//t_color3	write_color(t_color3 *color);

void	ft_camera_set(t_camera *cam, double aspect_ratio, t_point3 orig);

#endif
