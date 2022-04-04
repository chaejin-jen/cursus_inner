/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:03:22 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 04:18:17 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	print_sort_op(t_sort_op *op, t_sort location)
{
	if (location == TOP)
		printf(">>>>>>>>>>[TOP] sort option checking!\n");
	else if (location == MID)
		printf(">>>>>>>>>>[MID] sort option checking!\n");
	else if (location == BOT)
		printf(">>>>>>>>>>[BOT] sort option checking!\n");
	else
		printf("??????????[%d] sort option checking!\n", location);
	if (op->sort_dst == A)
		printf("sort dst : %c\n", 'A');
	else if (op->sort_dst == B)
		printf("sort dst : %c\n", 'B');
	else
		printf("sort dst : %d\n", op->sort_dst);
	if (op->sort_order == ASC)
		printf("sort order : 'ASCENDING'\n");
	else if (op->sort_order == DESC)
		printf("sort order : 'DESCENDING'\n");
	else
		printf("sort order : %d\n", op->sort_order);
}

static void	prnt_one(t_list **a, t_list **b, int *a_size, int *b_size)
{
	while (*a_size != *b_size)
	{
		if (*a_size > *b_size)
		{
			(*a_size)--;
			printf(" \t%ld\n", (long)((*a)->content));
			*a = (*a)->next;
		}
		else
		{
			(*b_size)--;
			printf("\t\t%ld\n", (long)((*b)->content));
			*b = (*b)->next;
		}
	}
}

void	print_two_lst(t_stack *s1, t_stack *s2)
{
	int		a_size;
	int		b_size;
	t_list	*a;
	t_list	*b;

	a = s1->data;
	b = s2->data;
	a_size = ft_lstsize(a);
	b_size = ft_lstsize(b);
	printf("=============stack==============\n");
	while (a_size || b_size)
	{
		prnt_one(&a, &b, &a_size, &b_size);
		if (a_size-- == 0 && b_size == 0)
			return ;
		printf(" \t%ld\t%ld\n", (long)(a->content), (long)(b->content));
		b_size--;
		a = a->next;
		b = b->next;
	}
	printf(" \t-\t-\n \ta\tb\n head : %ld\t%ld\n",
		(long)s1->info.head->content, (long)s2->info.head->content);
	printf(" tail : %ld\t%ld\n",
		(long)s1->info.tail->content, (long)s2->info.tail->content);
	printf(" size : %d\t%d\n", s1->info.size, s2->info.size);
}
