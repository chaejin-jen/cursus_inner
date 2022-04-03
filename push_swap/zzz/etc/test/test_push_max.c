#include "push_swap.h"

void	push_max(t_stack *a, t_stack *b)
{
	if (a->info.len < 3)
	{
		if (a->info.len == 1)
			push(a, b, FALSE);\
		if (a->info.head->content > a->info.tail->content)
			push(a, b, FALSE);
		else
		{
			swap(a, TRUE, FALSE);
			push(a, b, FALSE);
		}
		return ;
	}
	if (a->info.head->content > a->info.head->next->content && a->info.head->content > a->info.tail->content)
		push(a, b, FALSE);
	else if (a->info.head->next->content > a->info.head->content && a->info.head->next->content > a->info.tail->content)
	{
		swap(a, TRUE, FALSE);
		push(a, b, FALSE);
	}
	else
	{
		rotate(a, TRUE, TRUE, FALSE);
		push(a, b, FALSE);
	}
}

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	//t_sort_info info;

	if (argc < 2)
		print_error();
	stack_init(&a, TRUE);
	stack_init(&b, TRUE);
	argv_to_lst(&a, argc, argv);
	//sort_init(&info);
	print_two_lst(a.data, b.data);

	while (a.info.len)
	{
		push_max(&a, &b);
		printf("push_max\n");
		print_two_lst(a.data, b.data);
	}
}
