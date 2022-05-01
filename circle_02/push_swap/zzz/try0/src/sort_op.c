/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 05:53:41 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 04:58:27 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_op_init(t_sort_op *op)
{
	op->rr_size = 0;
	op->sector = TOP;
	op->dst = A;
	op->order = ASC;
}

void	sort_top_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sector = TOP;
	new_op->dst = B;
	new_op->order = op->order;
}

void	sort_mid_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sector = MID;
	new_op->dst = A;
	new_op->order = op->order;
}

void	sort_bot_op_set(t_sort_op *new_op, t_sort_op *op)
{
	new_op->rr_size = 0;
	new_op->sector = BOT;
	new_op->dst = !(op->dst);
	new_op->order = !(op->order);
}
