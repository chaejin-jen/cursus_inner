#include "so_long.h"

void	read_error(char *message)
{
	write(1, "Error\n", 7);
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	exit(0);
}

void	null_error(t_game *game, char *message)
{
	write(1, "Error\n", 7);
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	exit(0);
}

void	molloc_error(t_game *game, int error_code, char *message)
{
	write(1, "Error\n", 7);
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	exit(0);
}

void	map_error(t_map *map, char *message)
{
	write(1, "Error\n", 7);
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	ft_lstclear(&map->tmp_lst, del_ptr);
	ft_lstclear(&map->exit_lst, free);
	free(map);
	exit(0);
}
