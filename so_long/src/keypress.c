#include "so_long.h"

static void	restart(t_game *game, t_map *map, t_player *player)
{
	player->pos.x = player->pos_init.x;
	player->pos.y = player->pos_init.y;
	map->obj_c = map->obj_c_init;
	game->play = 1;
	render_map(game);	
}

int	keypress(int key, t_game *game)
{
	t_vector	p_pos;

	p_pos = game->map->player.pos;
	if (key == KEY_ESC)
		game_exit(0);
	if (game->play && (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D))
		set_player(key, game, p_pos.x, p_pos.y);
	if (game->play == 0 && key == KEY_R)
		restart(game, game->map, &game->map->player);
	if (key == 6)
	{
		printf("ft_lstclear working..\n");
		ft_lstclear(&game->map->exit_lst, free);
		printf("success\n");
	}
	if (key == 7)
	{
		printf("free_pptr working..\n");
		free_pptr(game->map->data);
		printf("success\n");

	}
	if (key == 8)
	{
		printf("free working..\n");
		free(game->map);
		printf("success\n");
	}
	return (key);
}
