#include "so_long.h"

t_vector	vector_init(int x, int y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	calc_vector(t_vector dst_pos, t_vector cur_pos)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	if (dst_pos.x < cur_pos.x)
		pos.x = -1;
	else if(dst_pos.x > cur_pos.x)
		pos.x = 1;
	if (dst_pos.y < cur_pos.y)
		pos.y = -1;
	else if(dst_pos.y > cur_pos.y)
		pos.y = 1;
	return (pos);
}

t_list	*lst_init()
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		/* "malloc failed (t_list lst)\n" */
		/* map, lst free */
		read_error("malloc failed (t_list lst)\n");
	//lst = 0;
	lst->content = 0;
	lst->next = 0;
	return (lst);
}

void	del_ptr(void *ptr)
{
	ptr = 0;
}

void	free_pptr(char **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
	{
		free(pptr[i]);
		pptr[i] = 0;
		i++;
	}
	free(pptr);
	pptr = 0;
	return ;
}
