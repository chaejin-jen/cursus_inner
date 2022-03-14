#include "so_long.h"

int	keypress(int key, t_game *game)
{
	t_vector	p_pos;

	p_pos = game->map->player.pos;
	if (key == KEY_ESC)
	{
		printf("you closed window - program exit\n");
		exit(0);
	}
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		set_player(key, game, p_pos.x, p_pos.y);
	return (key);
}
