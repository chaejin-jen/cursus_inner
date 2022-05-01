/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/30 17:41:17 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_up(t_game *game, t_map *map, int x, int y)
{
	char	obj;

	obj = map->data[y - 1][x];
	map->player.img_ptr = game->player_img.back;
	if (y == 0 || obj == '1' || (map->obj_c && obj == 'E'))
		return ;
	map->player.pos_next.x = x;
	map->player.pos_next.y = y - 1;
}

static void	player_down(t_game *game, t_map *map, int x, int y)
{
	char	obj;

	obj = map->data[y + 1][x];
	map->player.img_ptr = game->player_img.front;
	if (y == map->rows - 1 || obj == '1' || (map->obj_c && obj == 'E'))
		return ;
	map->player.pos_next.x = x;
	map->player.pos_next.y = y + 1;
}

static void	player_left(t_game *game, t_map *map, int x, int y)
{
	char	obj;

	obj = map->data[y][x - 1];
	map->player.img_ptr = game->player_img.left;
	if (x == 0 || obj == '1' || (map->obj_c && obj == 'E'))
		return ;
	map->player.pos_next.x = x - 1;
	map->player.pos_next.y = y;
}

static void	player_right(t_game *game, t_map *map, int x, int y)
{
	char	obj;

	obj = map->data[y][x + 1];
	map->player.img_ptr = game->player_img.right;
	if (x == map->cols - 1 || obj == '1' || (map->obj_c && obj == 'E'))
		return ;
	map->player.pos_next.x = x + 1;
	map->player.pos_next.y = y;
}

int	keypress(int key, t_game *game)
{
	t_vector	p_pos;

	p_pos = game->map->player.pos;
	if (key == KEY_ESC)
		game_exit(game);
	if (game->play)
	{
		game->map->player.direction = key;
		if (key == KEY_W || key == KEY_UP)
			player_up(game, game->map, p_pos.x, p_pos.y);
		else if (key == KEY_S || key == KEY_DOWN)
			player_down(game, game->map, p_pos.x, p_pos.y);
		else if (key == KEY_A || key == KEY_LEFT)
			player_left(game, game->map, p_pos.x, p_pos.y);
		else if (key == KEY_D || key == KEY_RIGHT)
			player_right(game, game->map, p_pos.x, p_pos.y);
	}
	return (key);
}
