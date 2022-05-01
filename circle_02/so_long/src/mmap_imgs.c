/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/30 16:53:08 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mmap_tile_imgs(t_game *game)
{
	game->tile_img.grass = mlx_xpm_file_to_image(game->mlx,
			"assets/tiles/grass_2.xpm",
			&game->img_size.x, &game->img_size.y);
	game->tile_img.water = mlx_xpm_file_to_image(game->mlx,
			"assets/tiles/water_0.xpm",
			&game->img_size.x, &game->img_size.y);
	game->tile_img.success = mlx_xpm_file_to_image(game->mlx,
			"assets/success.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	mmap_obj_imgs(t_game *game)
{
	game->obj_img.gem = mlx_xpm_file_to_image(game->mlx,
			"assets/collect/gem_small.xpm",
			&game->img_size.x, &game->img_size.y);
	game->obj_img.door_o = mlx_xpm_file_to_image(game->mlx,
			"assets/door/door_opened.xpm",
			&game->img_size.x, &game->img_size.y);
	game->obj_img.door_c = mlx_xpm_file_to_image(game->mlx,
			"assets/door/door_closed.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	mmap_player_imgs(t_game *game)
{
	game->player_img.front[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/front/front_3.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.front[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/front/front_4.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.front[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/front/front_5.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.back[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/back/back_3.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.back[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/back/back_4.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.back[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/back/back_5.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	mmap_player_sides_imgs(t_game *game)
{
	game->player_img.left[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/left/left_3.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.left[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/left/left_4.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.left[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/left/left_5.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.right[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/right/right_3.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.right[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/right/right_4.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.right[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/character/right/right_5.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	mmap_imgs(t_game *game)
{
	mmap_tile_imgs(game);
	mmap_obj_imgs(game);
	mmap_player_imgs(game);
	mmap_player_sides_imgs(game);
}
