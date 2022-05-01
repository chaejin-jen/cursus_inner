#include "so_long.h"

void	*get_player_img(t_game *game, t_player *player, int *dirction)
{
	void	*img_ptr;

	if (*dirction == KEY_W || *dirction == KEY_UP)
		img_ptr = game->player_img.back[1];
	else if (*dirction == KEY_S || *dirction == KEY_DOWN)
		img_ptr = game->player_img.front[1];
	else if (*dirction == KEY_A || *dirction == KEY_LEFT)
		img_ptr = game->player_img.left[1];
	else if (*dirction == KEY_D || *dirction == KEY_RIGHT)
		img_ptr = game->player_img.rignt[1];
	*direction = 0;
	return (img_ptr);
}
