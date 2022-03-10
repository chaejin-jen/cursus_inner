#include "so_long.h"

//void	free_exit()

int		close_window(t_game *game)
{
	ft_lstclear(&(game->map.lst), free);
	//mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	game_exit(t_game *game)
{
	ft_lstclear(&(game->map.lst), free);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	event_exit(t_game *game)
{
	exit(0);
}