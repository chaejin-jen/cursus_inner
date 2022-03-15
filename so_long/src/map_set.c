/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:16 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/15 15:51:51 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	obj_lst_add(t_map *map, int col, char obj_type)
{
	t_list		*new_lst;
	t_vector	*pos;

	pos = (t_vector *)malloc(sizeof(t_vector));
	if (!pos)
		read_error("malloc failed\n");
	pos->x = col;
	pos->y = map->rows - 1;
	new_lst = ft_lstnew((void *)pos);
	if (!new_lst)
		read_error("malloc failed\n");
	if (obj_type == 'E')
	{
		if (!map->obj_e)
			map->exit_lst = new_lst;
		else
			ft_lstadd_front(&map->exit_lst, new_lst);
	}
	else
	{
		if (!map->obj_c)
			map->collect_lst = new_lst;
		else
			ft_lstadd_front(&map->collect_lst, new_lst);
	}
}

static void	player_init(t_player *player, int row, int col)
{
	player->pos_init.x = col;
	player->pos_init.y = row;
	player->pos.x = col;
	player->pos.y = row;
	player->pos_next.x = col;
	player->pos_next.y = row;
	player->img_i = 1;
	player->img_pre_i = 0;
	player->direction = 0;
}

void	map_obj_set(t_map *map, char c, int col)
{
	if (c == 'C')
	{
		map->obj_c++;
		map->obj_c_init = map->obj_c;
		obj_lst_add(map, col, c);
	}
	else if (c == 'E')
	{
		obj_lst_add(map, col, c);
		map->obj_e++;
	}
	else if (c == 'P')
	{
		map->obj_p++;
		player_init(&map->player, map->rows - 1, col);
	}
}
