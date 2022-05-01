/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 05:53:41 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/16 20:24:46 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	t_list	*data;

	data = a->data;
	while (data->next)
	{
		if ((long)(data->content) > (long)(data->next->content))
			return (0);
		data = data->next;
	}
	return (1);
}

static void	swap_sort_three(t_stack *a)
{
	long	n[3];

	num_init(n, a->info.head);
	if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
	{
		rotate(a, A_REV);
		swap(a, A);
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
	else if (n[2] < n[0] && n[2] < n[1])
	{
		if (n[0] > n[1])
			swap(a, A);
		rotate(a, A_REV);
	}
}

static void	sort_four_five(t_stack *a, int size)
{
	int			len[3];
	t_stack		b;
	t_sort_op	op;

	stack_init(&b, a->data);
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
	ft_lstclear(&b.data, ft_del);
}

void	rotate_all_size(t_stack *src1, t_stack *src2, int size)
{
	while (size--)
		rotate_all(src1, src2, ALL);
}

void	sort(t_stack *a, int size)
{
	t_stack		b;
	t_sort_op	op;

	if (is_sorted(a))
		return ;
	if (size <= 5)
	{
		if (size <= 2)
			swap_sort(a, size, ASC);
		else if (size == 3)
			swap_sort_three(a);
		else
			sort_four_five(a, size);
		return ;
	}
	stack_init(&b, a->data);
	sort_op_init(&op);
	sort_complex(a, &b, size, op);
	ft_lstclear(&b.data, ft_del);
}
