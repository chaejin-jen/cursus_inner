#include "so_long.h"

void	print_lst(t_map *map)
{
	int	row;
	t_list	*lst;

	lst = map->lst;
	row = -1;
	while (++row < map->rows)
	{
		printf("row : %d \t content : %s\n", row, (char *)(map->lst->content));
		//printf("row : %d \t content[11] : %c\n", row, ((char *)(map->lst->content))[11]);
		lst = lst->next;
	}
}
