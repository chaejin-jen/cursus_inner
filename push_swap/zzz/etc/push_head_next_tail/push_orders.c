/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_orders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:04:31 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/26 21:57:37 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void num_init(long *num, t_list *lst)
{
	num[0] = (long)lst->content;
	num[1] = (long)lst->next->content;
	num[2] = (long)lst->next->next->content;
}

static void push_small_sort(t_stack *dst, t_stack *src, t_flag flag, t_bool is_ascending)
{
	if (src->info.sort->loc_size == 1)
		push(dst, src, flag);
	else if (src->info.sort->loc_size == 2)
	{
		if (is_ascending)
		{
			if ((long)src->data->content > (long)src->data->next->content)
				swap(dst, !flag);
		}
		else
		{
			if ((long)src->data->content > (long)src->data->next->content)
				swap(dst, !flag);
		}
		push_size(dst, src, !flag, 2);
	}
}

void push_ascending(t_stack *dst, t_stack *src, t_flag flag)
{
	long n[3];

	if (src->info.sort->loc_size < 3)
	{
		push_small_sort(dst, src, flag, TRUE);
		return;
	}
	num_init(n, src->info.head);
	if (n[0] > n[1] && n[0] > n[2] && n[1] > n[2])
		push_size(dst, src, flag, 3);
	else if (n[0] > n[1] && n[0] > n[2] && n[1] < n[2])
		push_head_tail_next(dst, src, flag);
	else if (n[1] > n[0] && n[1] > n[2] && n[0] > n[2])
		push_next_head_tail(dst, src, flag);
	else if (n[1] > n[0] && n[1] > n[2] && n[0] < n[2])
		push_next_tail_head(dst, src, flag);
	else if (n[2] > n[0] && n[2] > n[1] && n[0] > n[1])
		push_tail_head_next(dst, src, flag);
	else if (n[2] > n[0] && n[2] > n[1] && n[0] < n[1])
		push_tail_next_head(dst, src, flag);
}

void push_descending(t_stack *dst, t_stack *src, t_flag flag)
{
	long n[3];

	if (src->info.sort->loc_size < 3)
	{
		push_small_sort(dst, src, flag, FALSE);
		return;
	}
	num_init(n, src->info.head->content,
			 src->info.head->next->content, src->info.tail->content);
	if (n[0] < n[1] && n[0] < n[2] && n[1] < n[2])
		push_size(dst, src, flag, 3);
	else if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
		push_head_tail_next(dst, src, flag);
	else if (n[1] < n[0] && n[1] < n[2] && n[0] < n[2])
		push_next_head_tail(dst, src, flag);
	else if (n[1] < n[0] && n[1] < n[2] && n[0] > n[2])
		push_next_tail_head(dst, src, flag);
	else if (n[2] < n[0] && n[2] < n[1] && n[0] < n[1])
		push_tail_head_next(dst, src, flag);
	else if (n[2] < n[0] && n[2] < n[1] && n[0] > n[1])
		push_tail_next_head(dst, src, flag);
}

/*





*/
