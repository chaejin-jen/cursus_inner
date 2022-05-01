/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:16 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/23 22:45:53 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_lst_add(t_map *map, int col)
{
	t_list		*new_lst;
	t_vector	*pos;

	pos = (t_vector *)malloc(sizeof(t_vector));
	if (pos == NULL)
		map_error(map, "malloc failed\n");
	pos->x = col;
	pos->y = map->rows - 1;
	if (map->obj_e == 0)
	{
		free(map->exit_lst->content);
		map->exit_lst->content = pos;
		return ;
	}
	new_lst = ft_lstnew((void *)pos);
	if (new_lst == NULL)
		map_error(map, "malloc failed\n");
	ft_lstadd_front(&map->exit_lst, new_lst);
}

static void	col_lst_add(t_map *map, int col)
{
	t_list		*new_lst;
	t_vector	*pos;

	pos = (t_vector *)malloc(sizeof(t_vector));
	if (pos == NULL)
		map_error(map, "malloc failed\n");
	pos->x = col;
	pos->y = map->rows - 1;
	if (map->obj_c == 0)
	{
		free(map->collect_lst->content);
		map->collect_lst->content = pos;
		return ;
	}
	new_lst = ft_lstnew((void *)pos);
	if (new_lst == NULL)
		map_error(map, "malloc failed\n");
	ft_lstadd_front(&map->collect_lst, new_lst);
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
	player->direction = -1;
}

void	map_obj_set(t_map *map, char c, int col)
{
	if (c == 'C')
	{
		col_lst_add(map, col);
		map->obj_c++;
	}
	else if (c == 'E')
	{
		exit_lst_add(map, col);
		map->obj_e++;
	}
	else if (c == 'P')
	{
		map->obj_p++;
		player_init(&map->player, map->rows - 1, col);
	}
}
