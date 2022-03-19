/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:18 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/19 16:23:37 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	valid_object(t_map *map, char *buf)
{
	int	col;

	if (*buf == '\n')
		return ;
	col = -1;
	while (++col < map->cols)
	{
		if (*buf != '0' && *buf != '1' && *buf != 'C'
			&& *buf != 'E' && *buf != 'P' && *buf != '\n')
			map_error(map, "unvalid charcters\
					\nnote: '0(empty)', '1(wall)',\
					\n\t'C(collection)', 'E(exit)', 'P(player)'\n");
		map_obj_set(map, *buf, col);
		buf++;
	}
}

static void	valid_rectangle_map(t_map *map, char *buf, int cols)
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

static void	valid_wall(t_map *map,
		char *buf, int cols, int buf_len)
{
	int	i;

	if (map->rows == 1 || (buf_len != BUFFER_SIZE && cols == -1))
	{
		i = 0;
		while (i < map->cols)
		{
			if (*buf != '1')
				map_error(map, "not rectangle walls (top/bottom)\n");
			buf++;
			i++;
		}
		return ;
	}
	if (*buf != '1' || *(buf + map->cols - 1) != '1')
		map_error(map, "not rectangle walls (left/right)\n");
}

void	map_valid(t_map *map, char *buf, int cols, int buf_len)
{
	valid_object(map, buf);
	valid_rectangle_map(map, buf, cols);
	valid_wall(map, buf, cols, buf_len);
}

void	valid_obj_num(t_map *map)
{
	if (map->obj_p != 1)
		map_error(map, "unvalid number of players (only 1 available)\n");
	if (map->obj_c == 0)
		map_error(map, "unvalid number of collectables (at least 1)\n");
	if (map->obj_e == 0)
		map_error(map, "unvalid number of exits (at least 1)\n");
}
