#include "so_long.h"

void	print_lst(t_map *map, t_list *lst)
{
	int	row;

	row = -1;
	while (++row < map->rows)
	{
		//printf("map->rows : %d, lst : %p, lst->content : %p, lst->next : %p\n", map->rows, lst, lst->content, lst->next);
		printf("row : %d \t content : %s|\n", row, (char *)(lst->content));
		//printf("row : %d \t content[11] : %c\n", row, ((char *)(lst->content))[11]);
		lst = lst->next;
	}
}
