#include "so_long.h"

// void	free_exit()

int		close_window(t_game *game)
{
	write(1, "you closed window\n", 19);
	ft_lstclear(&game->map->exit_lst, free);
	free_pptr(game->map->data);
	free(game->map);
	// mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	game_exit(t_game *game)
{
	write(1, "program exit\n", 14);
	ft_lstclear(&game->map->exit_lst, free);
	free_pptr(game->map->data);
	free(game->map);
	exit(0);
}
