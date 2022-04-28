/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:10:22 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 05:01:59 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_num_init(t_stack *a, t_stack *b, long *num, t_flag dst)
{
	num[TOP] = (long)b->info.tail->content;
	num[MID] = (long)a->info.tail->content;
	if (dst == A)
		num[BOT] = (long)b->info.head->content;
	else
		num[BOT] = (long)a->info.head->content;
}

t_sort	get_merge_location(long *n, t_sort order)
{
	if (order == ASC)
	{
		if (n[0] > n[1] && n[0] > n[2])
			return (TOP);
		else if (n[1] > n[0] && n[1] > n[2])
			return (MID);
		else
			return (BOT);
	}
	if (n[0] < n[1] && n[0] < n[2])
		return (TOP);
	else if (n[1] < n[0] && n[1] < n[2])
		return (MID);
	else
		return (BOT);
}

t_sort	cmp_top_mid(t_stack *a, t_stack *b, t_sort_op *op)
{
	long	n[2];

	n[0] = (long)(b->info.tail->content);
	n[1] = (long)(a->info.tail->content);
	if (op->order == ASC)
	{
		if (n[0] > n[1])
			return (TOP);
		else
			return (MID);
	}
	if (n[0] < n[1])
		return (TOP);
	else
		return (MID);
}

t_sort	cmp_top_bot(t_stack *a, t_stack *b, t_sort_op *op)
{
	long	n[2];

	n[0] = (long)(b->info.tail->content);
	if (op->dst == A)
		n[1] = (long)(b->info.head->content);
	else
		n[1] = (long)(a->info.head->content);
	if (op->order == ASC)
	{
		if (n[0] > n[1])
			return (TOP);
		else
			return (BOT);
	}
	if (n[0] < n[1])
		return (TOP);
	else
		return (BOT);
}

t_sort	cmp_mid_bot(t_stack *a, t_stack *b, t_sort_op *op)
{
	long	n[2];

	n[0] = (long)(a->info.tail->content);
	if (op->dst == A)
		n[1] = (long)(b->info.head->content);
	else
		n[1] = (long)(a->info.head->content);
	if (op->order == ASC)
	{
		if (n[0] > n[1])
			return (MID);
		else
			return (BOT);
	}
	if (n[0] < n[1])
		return (MID);
	else
		return (BOT);
}
