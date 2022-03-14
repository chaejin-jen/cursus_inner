#include "so_long.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->rows = 0;
	map->cols = 0;
	map->obj_c = 0;
	map->obj_e = 0;
	map->obj_p = 0;
	map->player.pos.x = 0;
	map->player.pos.y = 0;
	map->exit_lst = 0;
	map->tmp_lst = 0;
	return (map);
}

void	map_obj_set(t_map *map, char c, int col)
{
	t_list		*new_lst;
	t_vector	*pos;

	if (c == 'C')
		map->obj_c++;
	else if (c == 'E')
	{
		pos = (t_vector *)malloc(sizeof(t_vector));
		pos->x = col;
		pos->y = map->rows - 1;
		new_lst = ft_lstnew((void *)pos);
		if (!new_lst)
			read_error("malloc failed\n");
		if (!map->obj_e)
			map->exit_lst = new_lst;
		else
			ft_lstadd_front(&map->exit_lst, new_lst);
		map->obj_e++;
	}
	else if (c == 'P')
	{
		map->obj_p++;
		map->player.pos_init.x = col;
		map->player.pos_init.y = map->rows - 1;
		map->player.pos.x = col;
		map->player.pos.y = map->rows - 1;
		map->player.pos_next.x = col;
		map->player.pos_next.y = map->rows - 1;
		map->player.img_i = 1;
		map->player.img_pre_i = 0;
		map->player.direction = 0;
	}
}
