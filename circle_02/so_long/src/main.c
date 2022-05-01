/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:13 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/15 14:45:59 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		read_error("unvaild argc (only one \".ber\" file path need)");
	map_parse(&game, argv[1]);
	game_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &keypress, &game);
	mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
