/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:06:47 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 04:20:38 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_next(t_stack *dst, t_stack *src, t_flag flag)
{
	swap(src, !flag);
	push(dst, src, flag);
}

static void	push_next_next(t_stack *dst, t_stack *src, t_flag flag)
{
	rotate(src, !flag);
	swap(src, !flag);
	push(dst, src, flag);
	rotate(src, !flag + REV);
}

static void	push_ascending(t_stack *b, t_stack *a)
{
	long	n[3];

	num_init(n, a->info.head);
	if (n[0] > n[1] && n[0] > n[2])
	{
		push(b, a, B);
		if (n[1] < n[2])
			swap(a, A);
	}
	else if (n[1] > n[0] && n[1] > n[2])
	{
		push_next(b, a, B);
		if (n[0] < n[2])
			swap(a, A);
	}
	else
	{
		push_next_next(b, a, B);
		if (n[0] < n[1])
			swap(a, A);
	}
	push(b, a, B);
	push(b, a, B);
}

static void	push_descending(t_stack *b, t_stack *a)
{
	long	n[3];

	num_init(n, a->info.head);
	if (n[0] < n[1] && n[0] < n[2])
	{
		push(b, a, B);
		if (n[1] > n[2])
			swap(a, A);
	}
	else if (n[1] < n[0] && n[1] < n[2])
	{
		push_next(b, a, B);
		if (n[0] > n[2])
			swap(a, A);
	}
	else
	{
		push_next_next(b, a, B);
		if (n[0] > n[1])
			swap(a, A);
	}
	push(b, a, B);
	push(b, a, B);
}

void	push_sort(t_stack *b, t_stack *a, int size, t_sort order)
{
	long	n[2];

	if (size < 1)
		return ;
	if (size < 3)
	{
		n[0] = (long)a->data->content;
		n[1] = (long)a->data->next->content;
		if (size == 1)
			push(b, a, B);
		if (size == 2)
		{
			if (((order == ASC) && (n[0] < n[1]))
				|| ((order == DESC) && (n[0] > n[1])))
				swap(a, A);
			push(b, a, B);
			push(b, a, B);
		}
		return ;
	}
	if (order == ASC)
		push_ascending(b, a);
	else
		push_descending(b, a);
}
