#include "so_long.h"
#include "so_long_int.h" // 나중에 지우기

static void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_size.x, game->win_size.y, "so long");
}

/*
static void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}
*/

void	game_init(t_game *game)
{
	window_init(game);
	mmap_imgs(game);
	//img_init(game);
	//render_map_init(game);
	//mlx_put_image_to_window(game->mlx, game->win,
	//game->tile_img.grass, TILE_SIZE, 0);
}
