/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:37:53 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 03:43:17 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_sort_three(t_stack *a)
{
	long	n[3];

	num_init(n, a->info.head);
	if (n[0] < n[1] && n[0] < n[2])
	{
		if (n[1] > n[2])
		{
			rotate(a, A_REV);
			swap(a, A);
		}
	}
	else if (n[1] < n[0] && n[1] < n[2])
	{
		if (n[0] > n[2])
		{
			rotate(a, A);
			return ;
		}
		swap(a, A);
	}
	else
	{
		if (n[0] > n[1])
			swap(a, A);
		rotate(a, A_REV);
	}
}

void	sort_simple(t_stack *a, int size)
{
	int			len[3];
	t_stack		b;
	t_sort_op	op;

	if (size <= 2)
	{
		swap_sort(a, size, ASC);
		return ;
	}
	else if (size == 3)
	{
		swap_sort_three(a);
		return ;
	}
	stack_init(&b);
	sort_op_init(&op);
	len[TOP] = size / 3;
	len[MID] = size / 3 + size % 3;
	len[BOT] = size / 3;
	push(&b, a, B);
	push(&b, a, B);
	if (size == 4)
		swap_sort(a, 2, ASC);
	if (size == 5)
		swap_sort_three(a);
	merge(a, &b, len, &op);
	free(b.data);
}
