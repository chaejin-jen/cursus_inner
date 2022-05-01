#include "so_long.h"

static void	mmap_tile_imgs(t_game *game)
{
	game->tile_img.grass = mlx_xpm_file_to_image(game->mlx,
			"assets/tiles/grass_2.xpm",
			&game->img_size.x, &game->img_size.y);
	game->tile_img.water = mlx_xpm_file_to_image(game->mlx,
			"assets/tiles/watter_0.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	mmap_obj_imgs(t_game *game)
{
	game->obj_img.coin = mlx_xpm_file_to_image(game->mlx,
			"assets/collect/coin_large",
			&game->img_size.x, &game->img_size.y);
	game->obj_img.gem = mlx_xpm_file_to_image(game->mlx,
			"assets/collect/gem_large.xpm",
			&game->img_size.x, &game->img_size.y);
	game->obj_img.door = mlx_xpm_file_to_image(game->mlx,
			"assets/door/door_B_0.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	mmap_player_imgs(t_game *game)
{
	game->player_img.front[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/front_3.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.front[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/front_4.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.front[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/front_5.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.back[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/back_3.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.back[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/back_4.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.back[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/back_5.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	mmap_player_sides_imgs(t_game *game)
{
	game->player_img.left[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/left_3.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.left[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/left_4.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.left[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/left_5.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.right[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/right_3.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.right[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/right_4.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player_img.right[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/charater/right_5.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	mmap_imgs(t_game *game)
{
	mmap_tile_imgs(game);
	mmap_obj_imgs(game);
	mmap_player_imgs(game);
	mmap_player_sides_imgs(game);
}