#include <stdio.h>
#include <stdlib.h>

/* output
clang ex_void_ptr.c -o ex_void_ptr && ./ex_void_ptr
0       content:2
1       content:4
2       content:8
3       content:16
4       content:32
5       content:64
6       content:128
7       content:256
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);


void	f_2(t_list **lst, long a)
{
	t_list	*new_lst;

	new_lst = ft_lstnew((void *)a);
	ft_lstadd_back(lst, new_lst);
}

void	f_1(long a)
{
	static t_list	*lst = 0;
	t_list			*lst_copy;
	long				i;

	f_2(&lst, a);
	if (a == 256)
	{
		i = -1;
		lst_copy = lst;
		while (++i < 8)
		{
			printf("%ld\tcontent:%ld\n", i, (long)lst_copy->content);
			lst_copy = lst_copy->next;
		}
	}
}

int	main(void)
{
	long	a;
	int		b;

	b = 1;
	a = (long)b;
	while (a < 256)
	{
		a <<= 1;
		f_1(a);
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return ((void *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
