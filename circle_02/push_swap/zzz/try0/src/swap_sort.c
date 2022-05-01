/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:07:01 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 01:44:06 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_third_second(t_stack *src, t_flag flag)
{
	rotate(src, flag);
	swap(src, flag);
	rotate(src, flag + REV);
}

static void	swap_ascending(t_stack *a)
{
	long	n[3];

	num_init(n, a->info.head);
	if (n[0] < n[1] && n[0] < n[2])
	{
		if (n[1] > n[2])
			swap_third_second(a, A);
	}
	else if (n[1] < n[0] && n[1] < n[2])
	{
		swap(a, A);
		if (n[0] > n[2])
			swap_third_second(a, A);
	}
	else
	{
		if (n[0] > n[1])
			swap(a, A);
		swap_third_second(a, A);
		swap(a, A);
	}
}

static void	swap_descending(t_stack *a)
{
	long	n[3];

	num_init(n, a->info.head);
	if (n[0] > n[1] && n[0] > n[2])
	{
		if (n[1] < n[2])
			swap_third_second(a, A);
	}
	else if (n[1] > n[0] && n[1] > n[2])
	{
		swap(a, A);
		if (n[0] < n[2])
			swap_third_second(a, A);
	}
	else
	{
		if (n[0] < n[1])
			swap(a, A);
		swap_third_second(a, A);
		swap(a, A);
	}
}

void	swap_sort(t_stack *a, int size, t_sort order)
{
	long	n[2];

	if (size <= 1)
		return ;
	if (size < 3)
	{
		n[0] = (long)a->data->content;
		n[1] = (long)a->data->next->content;
		if (((order == ASC) && (n[0] > n[1]))
			|| ((order == DESC) && (n[0] < n[1])))
			swap(a, A);
		return ;
	}
	if (order == ASC)
		swap_ascending(a);
	else
		swap_descending(a);
}
