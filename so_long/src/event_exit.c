/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:49:49 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/15 17:29:20 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	write(1, "you closed window\n", 19);
	ft_lstclear(&game->map->exit_lst, free);
	ft_lstclear(&game->map->collect_lst, free);
	free_pptr(game->map->data);
	free(game->map);
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
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
