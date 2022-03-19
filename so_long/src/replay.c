/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:34 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/19 15:35:37 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collect_init(t_map *map)
{
	t_list		*lst;
	t_vector	*pos;

	lst = map->collect_lst;
	while (lst)
	{
		pos = (t_vector *)(lst->content);
		map->data[pos->y][pos->x] = 'C';
		lst = lst->next;
	}
}

void	replay(t_game *game, t_map *map, t_player *player)
{
	player->pos.x = player->pos_init.x;
	player->pos.y = player->pos_init.y;
	player->pos_next.x = player->pos_init.x;
	player->pos_next.y = player->pos_init.y;
	map->obj_c = map->obj_c_init;
	game->play = 1;
	game->move_count = 0;
	collect_init(game->map);
	render_map(game);
}
