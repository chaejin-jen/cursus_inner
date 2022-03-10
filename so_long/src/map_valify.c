#include "so_long.h"

void	valid_object(t_map *map, char *buf, int cols)
{
	while (--cols)
	{
		if (*buf != '0' && *buf != '1' && *buf != 'C' && *buf != 'E' && *buf != 'P')
			map_error(map, "valid charcters only '0(ground)', '1(wall)', 'C(collection)', 'E(exit)', 'P(player)'\n");
		if (*buf == 'C')
			map_obj_set(map, *buf);
		else if (*buf == 'E')
			map_obj_set(map, *buf);
		else if (*buf == 'P')
			map_obj_set(map, *buf);
		buf++;
	}
}

void	valid_rectangle_map(t_map *map, char *buf, int cols)
{
	if (map->cols == 0)
		map_error(map, "empty line in map\n");
	if (cols == -1)
	{
		while (*(buf + cols))
			cols++;
	}
	else if (cols == 0)
		map_error(map, "empty line in map\n");
	if (cols != map->cols)
		map_error(map, "not rectangle map\n");
}

void	valid_wall(t_map *map, char *buf, int cols, int buf_len)
{
	int	i;

	if (map->rows == 0 || (buf_len != BUFFER_SIZE && cols == -1))
	{
		i = 0;
		while (i < map->cols)
		{
			if (*buf != '1')
				map_error(map, "The map must be a rectangle surrounded by walls '1'(top, bottom)\n");
			buf++;
			i++;
		}
		return ;
	}
	if (*buf != '1' || *(buf + map->cols - 1) != '1') // buf + map->cols - 1 이 맞나?
		map_error(map, "The map must be a rectangle surrounded by walls '1'(side)\n");
}

void	valid_object_num(t_map *map)
{
	printf("valid_object_num\n obj_c : %d, obj_p : %d, obj_e : %d\n", map->obj_c, map->obj_p, map->obj_e);
	if (map->obj_p != 1)
		map_error(map, "unvalid number of players (only 1 available)\n");
	if (map->obj_c == 0)
		map_error(map, "unvalid number of collectables (at least more then 1)\n");
	if (map->obj_e == 0)
		map_error(map, "unvalid number of exits (at least more then 1)\n");
}
