#include "so_long.h"

t_list	*lst_init()
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		/* "malloc failed (t_list lst)\n" */
		/* map, lst free */
		read_error("malloc failed (t_list lst)\n");
	lst->content = 0;
	lst->next = 0;
	return (lst);
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
