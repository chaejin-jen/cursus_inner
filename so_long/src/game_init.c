#include "so_long.h"
#include "so_long_int.h" // 나중에 지우기

static void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->win_size.x, game->win_size.y, "so long");
}

void	game_init(t_game *game)
{
	window_init(game);
	mmap_imgs(game);
	render_map(game);
	game->play = 1;
}
