#include "so_long.h"

void move_player(t_game *game, int keycode)
{
	char *str;

	if (keycode == KEY_W)
		str = "W";
	else if (keycode == KEY_S)
		str = "S";
	else if (keycode == KEY_A)
		str = "A";
	else if (keycode == KEY_D)
		str = "D";
	printf("%p\n", game->mlx);
	printf("%s\n", str);
}

int keypress(int keycode, t_game *game)
{
	// if (keycode == KEY_ESC)
	//	exit_game(game);
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
		move_player(game, keycode);
	if (keycode == KEY_ESC)
	{
		printf("%p\n", game->mlx);
		exit(0);
	}
	return (keycode);
}