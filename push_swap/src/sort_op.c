/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 05:53:41 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 04:27:24 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_op_init(t_sort_op *op)
{
	op->rr_size = 0;
	op->sort_loc = TOP;
	op->sort_dst = A;
	op->sort_order = ASC;
}

void	sort_top_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sort_loc = TOP;
	new_op->sort_dst = B;
	new_op->sort_order = op->sort_order;
}

void	sort_mid_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sort_loc = MID;
	new_op->sort_dst = A;
	new_op->sort_order = op->sort_order;
}

void	sort_bot_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sort_loc = BOT;
	new_op->sort_dst = !(op->sort_dst);
	new_op->sort_order = !(op->sort_order);
}
