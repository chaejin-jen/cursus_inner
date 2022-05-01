#include "push_swap.h"
#include "stdio.h"

void	print_lst(t_list *lst)
{
	int	row;

	row = -1;
	while (lst)
	{
		printf("row : %d \t content : %ld|\n", ++row, (long)(lst->content));
		lst = lst->next;
	}
}

void	print_two_lst(t_list *a, t_list *b)
{
	int	a_size;
	int	b_size;

	a_size = ft_lstsize(a);
	b_size = ft_lstsize(b);

	printf("=============stack==============\n");
	while (a_size || b_size)
	{
		while (a_size != b_size)
		{
			if (a_size > b_size)
			{
				a_size--;
				printf(" %ld\n",(long)(a->content));
				a = a->next;
			}
			else
			{
				b_size--;
				printf("\t%ld\n",(long)(b->content));
				b = b->next;
			}
		}
		if (a_size == 0 && b_size == 0)
			return ;
		printf(" %ld\t%ld\n",(long)(a->content), (long)(b->content));
		a_size--;
		b_size--;
		a = a->next;
		b = b->next;
	}
	printf(" -\t-\n a\tb\n");

}

void	print_info(t_stack_info info)
{
	printf("head->content : %ld\n", (long)info.head->content);
	printf("tail->content : %ld\n", (long)info.tail->content);
	printf("info len : %d\n\n", info.len);
}

void	print_test(t_stack a, t_stack b)
{
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);
}
