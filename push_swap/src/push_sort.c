/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:06:47 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 18:33:37 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_small_sort(t_stack *b, t_stack *a, int size, t_sort sort_order)
{
	if (size == 1)
	{
		push(b, a, B);
		return ;
	}
	if (sort_order == ASCENDING)
	{
		if ((long)a->data->content < (long)a->data->next->content)
			swap(a, A);
	}
	else
	{
		if ((long)a->data->content > (long)a->data->next->content)
			swap(a, A);
	}
	push_size(b, a, B, 2);
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
	push_size(b, a, B, 2);
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
	push_size(b, a, B, 2);
}

void	push_sort(t_stack *b, t_stack *a, int size, t_sort sort_order)
{
	if (size < 1)
		return ;
	if (size < 3)
	{
		push_small_sort(b, a, size, sort_order);
		return ;
	}
	if (sort_order == ASCENDING)
		push_ascending(b, a);
	else
		push_descending(b, a);
}
