/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:50:08 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 18:25:34 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_push(t_stack *a, t_stack *b, t_flag dst)
{
	if (dst == A)
	{
		rotate(b, B_REV);
		push(a, b, A);
		return ;
	}
	rotate(a, A_REV);
	push(b, a, B);
}

static void	merge_rest_one(t_stack *a, t_stack *b, int *len, t_sort_op *op)
{
	if (len[TOP])
	{
		if (op->merge_dst == A)
			reverse_push(a, b, A);
		else
			rotate(b, B_REV);
		len[TOP]--;
	}
	else if (len[MID])
	{
		if (op->merge_dst == A)
			rotate(a, A_REV);
		else
			reverse_push(a, b, B);
		len[MID]--;
	}
	else
	{
		if (op->merge_dst == A)
			push(a, b, A);
		else
			push(b, a, B);
		len[BOT]--;
	}
}

static void	merge_rest_two(t_stack *a, t_stack *b, int *len, t_sort_op *op)
{
	t_sort	merge_loc;

	if (len[TOP] && len[MID] && !len[BOT])
		merge_loc = cmp_top_mid(a, b, op);
	if (len[TOP] && !len[MID] && len[BOT])
		merge_loc = cmp_top_bot(a, b, op);
	if (!len[TOP] && len[MID] && len[BOT])
		merge_loc = cmp_mid_bot(a, b, op);
	len[merge_loc]--;
	if (op->merge_dst == A)
	{
		if (merge_loc == TOP)
			reverse_push(a, b, A);
		else if (merge_loc == MID)
			rotate(a, A_REV);
		else
			push(a, b, A);
		return ;
	}
	if (merge_loc == TOP)
		rotate(b, B_REV);
	else if (merge_loc == MID)
		reverse_push(a, b, B);
	else
		push(b, a, B);
}

static void	merge_three(t_stack *a, t_stack *b, int *len, t_sort_op *op)
{
	long	merge_num[3];
	t_sort	merge_loc;

	merge_num_init(a, b, merge_num, op->merge_dst);
	merge_loc = get_merge_location(merge_num, op->sort_order);
	// printf("merge_three\n");
	// printf("merge_loc = %d\n", merge_loc);
	len[merge_loc]--;
	if (op->merge_dst == A)
	{
		if (merge_loc == TOP)
			reverse_push(a, b, A);
		else if (merge_loc == MID)
			rotate(a, A_REV);
		else
			push(a, b, A);
		return ;
	}
	if (merge_loc == TOP)
		rotate(b, B_REV);
	else if (merge_loc == MID)
		reverse_push(a, b, B);
	else
		push(b, a, B);
}

void	merge(t_stack *a, t_stack *b, int *len, t_sort_op *op)
{
	int	rest;

	rest = !!len[TOP] + !!len[MID] + !!len[BOT];
	// printf("==========merge (size :%d)=======\n", len[TOP] + len[MID] + len[BOT]);
	// printf("sort_loc : %d\n", op->sort_loc);
	// printf("rr_size : %d\n", op->rr_size);
	// printf("len[TOP] = %d\n", len[TOP]);
	// printf("len[MID] = %d\n", len[MID]);
	// printf("len[BOT] = %d\n", len[BOT]);
	if (op->sort_loc == MID)
		op->rr_size++;
	if (rest == 0)
	{
		if (op->rr_size)
			rotate_all_size(a, b, op->rr_size - 1);
		return ;
	}
	else if (rest == 1)
		merge_rest_one(a, b, len, op);
	else if (rest == 2)
		merge_rest_two(a, b, len, op);
	else
		merge_three(a, b, len, op);
	// print_two_lst(a, b);
	merge(a, b, len, op);
}
