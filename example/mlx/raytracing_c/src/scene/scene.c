#include "scene.h"
#include "object.h"
#include <stdlib.h>

static t_object	*object_init(void)
{
	t_object	*obj;
	
	obj = create_object(SP, create_sphere(ft_vec3_set(-2, 0, -5), 2), ft_vec3_set(1, 0, 0)); // obj 에 구1 추가
	oadd(&obj, create_object(SP, create_sphere(ft_vec3_set(2, 0, -5), 2), ft_vec3_set(0, 1, 0))); // obj 에 구2 추가
	oadd(&obj, create_object(SP, create_sphere(ft_vec3_set(0, -1000, 0), 999), ft_vec3_set(1, 1, 1))); // obj 에 구3 추가
	return (obj);
}

t_scene	*scene_init(int width, int height)
{
	t_scene		*scene;
	t_object	*lights;
	double		ka;
	t_point3	orig;
	t_color3	color;
	t_vec3		vec3;
	t_point3	center;

	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL); // TODO : program exit
	ft_camera_set(&scene->camera, 16.0 / 9.0, ft_vec3_set(0, 0, 0));
	scene->object = object_init();
	lights = create_object(LIGHT,
		(void *)light_point(ft_vec3_set(0, 5, 0), ft_vec3_set(1, 1, 1), 0.5),
		ft_vec3_set(0, 0, 0)); // 더미 albedo
	scene->light = lights;
	ka = 0.1; // 8.4 에서 설명
	scene->ambient = ft_vec3_multi_scalar(ft_vec3_set(1, 1, 1), ka); // 반사율
	return (scene);
}