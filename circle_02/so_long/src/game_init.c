/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/02 00:18:33 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->win_size.x, game->win_size.y, "so long");
}

static void	player_init(t_player *player, int lines_num, int col)
{
	player->pos_init.x = col;
	player->pos_init.y = lines_num;
	player->pos.x = col;
	player->pos.y = lines_num;
	player->pos_next.x = col;
	player->pos_next.y = lines_num;
	player->img_i = 1;
	player->img_pre_i = 0;
	player->direction = -1;
}

static void	put_data(t_game *game, t_player *p, char c, t_vector pos)
{
	pos.x *= TILE_SIZE;
	pos.y *= TILE_SIZE;
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img.water, pos.x, pos.y);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img.grass, pos.x, pos.y);
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->obj_img.gem, pos.x + TILE_SIZE / 8, pos.y + TILE_SIZE / 8);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->obj_img.door_c, pos.x, pos.y - TILE_SIZE / 8);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			p->img_ptr[p->img_i], pos.x + TILE_SIZE / 8, pos.y + TILE_SIZE / 8);
	}
}

static void	render_map(t_game *game)
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
			if (data == 'P')
				player_init(&game->map->player, pos.y, pos.x);
			put_data(game, &game->map->player, data, pos);
			pos.x++;
		}
		pos.y++;
	}
	mlx_string_put(game->mlx, game->win, 16, 16, 0xFFFFFF, "0");
}

void	game_init(t_game *game)
{
	window_init(game);
	mmap_imgs(game);
	render_map(game);
	game->play = 1;
	game->move_count = 0;
}
