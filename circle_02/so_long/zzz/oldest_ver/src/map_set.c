#include "so_long.h"

t_map *map_init()
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->rows = 0;
	map->cols = 0;
	map->obj_c = 0;
	map->obj_e = 0;
	map->obj_p = 0;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	// map->lst = NULL;
	//map->lst = (t_list *)malloc(sizeof(t_list));
	//if (map->lst == NULL)
	//	read_error("malloc failed (t_map map->lst)\n");
	//map->lst->content = NULL;
	//map->lst->next = NULL;
	return (map);
}

void map_obj_set(t_map *map, char c)
{
	if (c == 'C')
		map->obj_c++;
	else if (c == 'E')
		map->obj_e++;
	else if (c == 'P')
	{
		map->obj_p++;
		map->player_pos.x = map->rows;
		map->player_pos.y = map->cols;
	}
}
