#include "so_long.h"

void	null_error(t_game game, char *message)
{
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	event_exit(&game);
}

void	read_error(char *message)
{
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	exit(0);
}

void	map_error(t_map *map, char *message)
{
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	ft_lstclear(&map->lst, free);
	exit(0);
}