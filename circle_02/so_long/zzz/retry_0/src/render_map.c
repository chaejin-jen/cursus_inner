/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:31 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:29:15 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_game *game, char c, t_vector pos)
{
	pos.x *= TILE_SIZE;
	pos.y *= TILE_SIZE;
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img.water, pos.x, pos.y);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img.grass, pos.x, pos.y);
}

static void	put_obj(t_game *game, t_player *p, char c, t_vector pos)
{
	pos.x *= TILE_SIZE;
	pos.y *= TILE_SIZE;
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->obj_img.gem,
			pos.x + TILE_SIZE / 8, pos.y + TILE_SIZE / 8);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->obj_img.door_c,
			pos.x, pos.y - TILE_SIZE / 8);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			p->img_ptr[p->img_i],
			pos.x + TILE_SIZE / 8, pos.y + TILE_SIZE / 8);
	}
}

void	render_map(t_game *game)
{
	t_vector	pos;
	char		**map_data;
	char		data;

	pos.y = 0;
	game->map->player.img_ptr = game->player_img.front;
	map_data = game->map->data;
	mlx_clear_window(game->mlx, game->win);
	while (pos.y < game->map->rows)
	{
		pos.x = 0;
		while (pos.x < game->map->cols)
		{
			data = map_data[pos.y][pos.x];
			put_tile(game, data, pos);
			put_obj(game, &game->map->player, data, pos);
			pos.x++;
		}
		pos.y++;
	}
}
