/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:07:01 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 18:32:14 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_small_sort(t_stack *a, t_stack *b,
	int size, t_sort sort_order)
{
	if (size == 1)
	{
		rotate_all(a, b, ALL);
		return ;
	}
	if (sort_order == ASCENDING)
	{
		if ((long)a->data->content > (long)a->data->next->content)
			swap(a, A);
	}
	else
	{
		if ((long)a->data->content < (long)a->data->next->content)
			swap(a, A);
	}
	rotate_all_size(a, b, 2);
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
		rotate_all(a, b, ALL);
	}
	else if (n[1] < n[0] && n[1] < n[2])
	{
		rotate_next(a, b, A);
		if (n[0] > n[2])
			swap(a, A);
		rotate_all(a, b, ALL);
	}
	else
	{
		rotate_next_next(a, b, A);
		if (n[0] > n[1])
			swap(a, A);
		rotate_all(a, b, ALL);
	}
	rotate_all(a, b, ALL);
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
		rotate_all(a, b, ALL);
	}
	else if (n[1] > n[0] && n[1] > n[2])
	{
		rotate_next(a, b, A);
		if (n[0] < n[2])
			swap(a, A);
		rotate_all(a, b, ALL);
	}
	else
	{
		rotate_next_next(a, b, A);
		if (n[0] < n[1])
			swap(a, A);
		rotate_all(a, b, ALL);
	}
	rotate_all(a, b, ALL);
}

void	rotate_sort(t_stack *a, t_stack *b, int size, t_sort sort_order)
{
	if (size < 1)
		return ;
	if (size < 3)
	{
		rotate_small_sort(a, b, size, sort_order);
		return ;
	}
	if (sort_order == ASCENDING)
		rotate_ascending(a, b);
	else
		rotate_descending(a, b);
}
