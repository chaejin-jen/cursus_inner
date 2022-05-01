/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:49:49 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/30 16:58:16 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_img(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->tile_img.grass);
	mlx_destroy_image(game->mlx, game->tile_img.water);
	mlx_destroy_image(game->mlx, game->tile_img.success);
	mlx_destroy_image(game->mlx, game->obj_img.gem);
	mlx_destroy_image(game->mlx, game->obj_img.door_o);
	mlx_destroy_image(game->mlx, game->obj_img.door_c);
	i = -1;
	while (++i < 3)
	{
		mlx_destroy_image(game->mlx, game->player_img.front[i]);
		mlx_destroy_image(game->mlx, game->player_img.back[i]);
		mlx_destroy_image(game->mlx, game->player_img.left[i]);
		mlx_destroy_image(game->mlx, game->player_img.right[i]);
	}
}

int	close_window(t_game *game)
{
	write(1, "you closed window\n", 19);
	ft_lstclear(&game->map->exit_lst, free);
	ft_lstclear(&game->map->collect_lst, free);
	free_pptr(game->map->data);
	free(game->map);
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	game_exit(t_game *game)
{
	write(1, "program exit\n", 14);
	ft_lstclear(&game->map->exit_lst, free);
	ft_lstclear(&game->map->collect_lst, free);
	free_pptr(game->map->data);
	free(game->map);
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
