/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:00:19 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 05:03:06 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_top(t_stack *a, t_stack *b, int size, t_sort_op op)
{
	if (size <= 3)
	{
		push_sort(b, a, size, op.order);
		return ;
	}
	sort_complex(a, b, size, op);
}

static void	sort_mid(t_stack *a, t_stack *b, int size, t_sort_op op)
{
	if (size <= 3)
	{
		rotate_sort(a, b, size, op.order);
		return ;
	}
	sort_complex(a, b, size, op);
}

static void	sort_bot(t_stack *a, t_stack *b, int size, t_sort_op op)
{
	if (size <= 3)
	{
		if (op.dst == A)
			swap_sort(a, size, op.order);
		else
			push_sort(b, a, size, op.order);
		return ;
	}
	sort_complex(a, b, size, op);
}

void	sort_complex(t_stack *a, t_stack *b, int size, t_sort_op op)
{
	int			len[3];
	t_sort_op	new_op;

	len[TOP] = size / 3;
	len[MID] = size / 3;
	len[BOT] = size / 3 + size % 3;
	sort_top_op_set(&new_op, &op);
	sort_top(a, b, len[TOP], new_op);
	sort_mid_op_set(&new_op, &op);
	sort_mid(a, b, len[MID], new_op);
	sort_bot_op_set(&new_op, &op);
	sort_bot(a, b, len[BOT], new_op);
	merge(a, b, len, &op);
}
