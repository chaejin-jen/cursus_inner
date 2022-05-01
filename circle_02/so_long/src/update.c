/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:51:40 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/30 18:08:23 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_img_i(t_player *player)
{
	if (player->img_i == 0)
	{
		player->img_i++;
		player->img_pre_i = 0;
	}
	else if (player->img_i == 2)
	{
		player->img_i--;
		player->img_pre_i = 2;
	}
	else if (player->img_i == 1 && player->img_pre_i == 0)
		player->img_i++;
	else if (player->img_i == 1 && player->img_pre_i == 2)
		player->img_i--;
}

static void	player_walk(t_game *game, t_player *player)
{
	t_vector	pos;

	pos.x = player->pos_next.x * TILE_SIZE + TILE_SIZE / 8;
	pos.y = player->pos_next.y * TILE_SIZE + TILE_SIZE / 8;
	set_img_i(player);
	if (game->play)
		mlx_put_image_to_window(game->mlx, game->win, game->tile_img.grass,
			player->pos.x * TILE_SIZE, player->pos.y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win,
		player->img_ptr[player->img_i], pos.x, pos.y);
	player->pos.x = player->pos_next.x;
	player->pos.y = player->pos_next.y;
}

static void	render(t_game *game, t_player *player)
{
	t_vector	pos;

	if (player->direction != -1)
	{
		pos = calc_vector(player->pos_next, player->pos);
		if (pos.x | pos.y)
			move_event(game, game->map, player->pos_next);
		player_walk(game, player);
		player->direction = -1;
	}
}

int	update(t_game *game)
{
	render(game, &game->map->player);
	return (0);
}
