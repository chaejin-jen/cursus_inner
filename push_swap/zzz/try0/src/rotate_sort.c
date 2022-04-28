/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:07:01 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 04:26:56 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_next(t_stack *src1, t_stack *src2, t_flag flag)
{
	swap(src1, flag);
	rotate_all(src1, src2, ALL);
}

static void	rotate_next_next(t_stack *src1, t_stack *src2, t_flag flag)
{
	push(src2, src1, !flag);
	swap_all(src1, src2);
	rotate_all(src1, src2, ALL);
	push(src1, src2, flag);
}

static void	rotate_ascending(t_stack *a, t_stack *b)
{
	long	n[3];

	num_init(n, a->info.head);
	if (n[0] < n[1] && n[0] < n[2])
	{
		rotate_all(a, b, ALL);
		if (n[1] > n[2])
			swap(a, A);
	}
	else if (n[1] < n[0] && n[1] < n[2])
	{
		rotate_next(a, b, A);
		if (n[0] > n[2])
			swap(a, A);
	}
	else
	{
		rotate_next_next(a, b, A);
		if (n[0] > n[1])
			swap(a, A);
	}
	rotate_all_size(a, b, 2);
}

static void	rotate_descending(t_stack *a, t_stack *b)
{
	long	n[3];

	num_init(n, a->info.head);
	if (n[0] > n[1] && n[0] > n[2])
	{
		rotate_all(a, b, ALL);
		if (n[1] < n[2])
			swap(a, A);
	}
	else if (n[1] > n[0] && n[1] > n[2])
	{
		rotate_next(a, b, A);
		if (n[0] < n[2])
			swap(a, A);
	}
	else
	{
		rotate_next_next(a, b, A);
		if (n[0] < n[1])
			swap(a, A);
	}
	rotate_all_size(a, b, 2);
}

void	rotate_sort(t_stack *a, t_stack *b, int size, t_sort order)
{
	long	n[2];

	if (size < 1)
		return ;
	if (size < 3)
	{
		n[0] = (long)a->data->content;
		n[1] = (long)a->data->next->content;
		if (size == 1)
			rotate_all(a, b, ALL);
		if (size == 2)
		{
			if (((order == ASC) && (n[0] > n[1]))
				|| ((order == DESC) && (n[0] < n[1])))
				swap(a, A);
			rotate_all_size(a, b, 2);
		}
		return ;
	}
	if (order == ASC)
		rotate_ascending(a, b);
	else
		rotate_descending(a, b);
}
