/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/15 17:19:21 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int key, t_game *game)
{
	t_vector	p_pos;

	p_pos = game->map->player.pos;
	if (key == KEY_ESC)
		game_exit(game);
	if (game->play && (key == KEY_UP || key == KEY_DOWN
			|| key == KEY_LEFT || key == KEY_RIGHT
			|| key == KEY_W || key == KEY_S
			|| key == KEY_A || key == KEY_D))
		set_player(key, game, p_pos.x, p_pos.y);
	if (!game->play && key == KEY_R)
		replay(game, game->map, &game->map->player);
	return (key);
}
