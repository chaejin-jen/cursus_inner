/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:24 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/30 17:04:01 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_int.h"

static void	door_open(t_game *game)
{
	t_list		*lst;
	t_vector	*pos;

	lst = game->map->exit_lst;
	while (lst)
	{
		pos = (t_vector *)(lst->content);
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img.grass, pos->x * TILE_SIZE, pos->y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->obj_img.door_o,
			pos->x * TILE_SIZE,
			pos->y * TILE_SIZE - TILE_SIZE / 8);
		lst = lst->next;
	}
}

static void	success(t_game *game, t_player *player)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tile_img.grass,
		player->pos.x * TILE_SIZE, player->pos.y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win,
		player->img_ptr[player->img_i],
		player->pos_next.x * TILE_SIZE + TILE_SIZE / 8,
		player->pos_next.y * TILE_SIZE + TILE_SIZE / 8);
	mlx_put_image_to_window(game->mlx, game->win, game->tile_img.success, 0, 0);
	game->play = 0;
	player->direction = -1;
}

void	move_event(t_game *game, t_map *map, t_vector pos)
{
	char	obj;

	printf("move : %d\n", ++game->move_count);
	obj = map->data[pos.y][pos.x];
	if (obj == 'C' && map->obj_c)
	{
		map->data[pos.y][pos.x] = '0';
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img.grass, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
		map->obj_c--;
		if (map->obj_c == 0)
			door_open(game);
	}
	else if (obj == 'E')
		success(game, &map->player);
}
