#include "so_long.h"

/*
int		render_next_frame(t_game *game)
{
	//draw_rectangles(game);
	//mlx_put_image_to_window(game.mlx, game.win, game.tile_img.grass, 0, 0);
	put_imgs(&game);
	return (0);
}
*/

int		main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		read_error("unvaild argc (only one \".ber\" file path need)");
	map_parse(&game, argv[1]);
	game_init(&game);
	mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &game);

	//mlx_loop_hook(game.mlx, update, &game);
	mlx_key_hook(game.win, keypress, &game);
	mlx_loop(game.mlx);
}
