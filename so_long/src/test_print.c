#include "so_long.h"

void	print_exit_lst(int exit_num, t_list *lst)
{
	int	i;
	t_vector	*pos;

	i = -1;
	while (++i < exit_num)
	{
		pos = (t_vector *)lst->content;
		printf("exit_obj_num : %d \t (%d, %d)\n", i, pos->x, pos->y);
		lst = lst->next;
	}
}

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
