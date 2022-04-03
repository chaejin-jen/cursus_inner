/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 05:53:41 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 17:16:34 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_op_init(t_sort_op *op)
{
	op->rr_size = 0;
	op->sort_loc = TOP;
	op->sort_dst = A;
	op->sort_order = ASCENDING;
	op->merge_loc = TOP;
	op->merge_dst = A;
	op->merge_order = ASCENDING;
}

void	sort_top_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sort_loc = TOP;
	new_op->sort_dst = B;
	new_op->sort_order = op->sort_order;
	new_op->merge_loc = TOP;
	new_op->merge_dst = B;
	new_op->merge_order = op->sort_order;
}

void	sort_mid_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sort_loc = MID;
	new_op->sort_dst = A;
	new_op->sort_order = op->sort_order;
	new_op->merge_loc = MID;
	new_op->merge_dst = A;
	new_op->merge_order = op->sort_order;
}

void	sort_bot_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sort_loc = BOT;
	new_op->sort_dst = !(op->sort_dst);
	new_op->sort_order = !(op->sort_order);
	new_op->merge_loc = BOT;
	new_op->merge_dst = !(op->sort_dst);
	new_op->merge_order = op->sort_order;
}
