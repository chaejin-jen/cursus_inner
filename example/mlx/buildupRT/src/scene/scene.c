#include "scene.h"
#include "object.h"
#include <stdlib.h>

//static t_object	*object_init(void)
//{
//	t_object	*obj;
	
//	obj = create_object(SP, create_sphere(vec_set(-2, 0, -5), 2), vec_set(1, 0, 0)); // obj 에 구1 추가
//	oadd(&obj, create_object(SP, create_sphere(vec_set(2, 0, -5), 2), vec_set(0, 1, 0))); // obj 에 구2 추가
//	oadd(&obj, create_object(SP, create_sphere(vec_set(0, -1000, 0), 999), vec_set(1, 1, 1))); // obj 에 구3 추가
//	return (obj);
//}

t_scene	*scene_init(int width, int height)
{
	t_scene		*scene;
	t_object	*object;
	t_object	*lights;
	double		ka; // 8.4 에서 설명
	t_point3	orig;
	t_color3	color;
	t_vec3		vec3;
	t_point3	center;

	// malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	//ft_canvas_set(&scene->canvas, width, height);
	ft_camera_set(&scene->camera, 16.0/9.0, vec_set(&vec3, 0, 0, 0));
	object = create_object(SP, create_sphere(vec_set(&center, -2, 0, -5), 2), vec_set(&vec3, 1, 0, 0)); // object 에 구1 추가
	oadd(&object, create_object(SP, create_sphere(vec_set(&center, 2, 0, -5), 2), vec_set(&vec3, 0, 1, 0))); // object 에 구2 추가
	oadd(&object, create_object(SP, create_sphere(vec_set(&center, 0, -1000, 0), 1000), vec_set(&vec3, 1, 1, 1))); // object 에 구3 추가
	scene->object = object;
	lights = create_object(LIGHT,
		(void *)create_light(vec_set(&orig, 0, 5, 0), vec_set(&vec3, 1, 1, 1), 0.5),
		vec_set(&color, 0, 0, 0)); // 더미 albedo
	scene->light = lights;
	ka = 0.1; // 8.4 에서 설명
	vec_mul_scalar(&scene->ambient, ka, vec_set(&vec3, 1, 1, 1)); // 반사율
	// printf("(scene_init) ambient : %f, %f, %f\n", scene->ambient.x, scene->ambient.y, scene->ambient.z);
	return (scene);
}
