/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:24 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/30 23:09:07 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_count_put(t_game *game)
{
	char	*move_count;

	move_count = ft_itoa(game->move_count);
	mlx_put_image_to_window(game->mlx, game->win, game->tile_img.water,
		0, 0);
	mlx_string_put(game->mlx, game->win, 16, 16, 0xFFFFFF, move_count);
	free(move_count);
}

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
	game->play = 0;
	player->direction = -1;
	mlx_string_put(game->mlx, game->win,
		game->win_size.x / 3, game->win_size.y / 3, 0xFFFFFF, "GAME SUCCESS!!");
	mlx_string_put(game->mlx, game->win, game->win_size.x / 3,
		game->win_size.y / 2, 0xFFFFFF, "Press \"Esc\" to exit");
}

void	move_event(t_game *game, t_map *map, t_vector pos)
{
	char	obj;

	printf("move : %d\n", ++game->move_count);
	obj = map->data[pos.y][pos.x];
	move_count_put(game);
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
