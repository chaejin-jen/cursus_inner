#include "so_long.h"

int 	close_window(t_game *game)
{
		exit(0);
}

int		main_loop(t_game *game)
{
	//draw_rectangles(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		exit(0);
	//map_init(&game, argv[1]);
	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_window, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_key_hook(game.win, keypress, &game);
	mlx_loop(game.mlx);
}
