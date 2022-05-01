/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:51:05 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/25 02:55:44 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src, t_bool is_dst_a)
{
	t_list	*src_next;

	if (src->info.len == 0)
		return ;
	src_next = src->data->next;
	if (++(dst->info.len) == 1)
	{
		src->info.null = src->data;
		dst->info.null = src->data;
	}
	stack_add(dst, src->data);
	dst->info.head = dst->data;
	if (--(src->info.len) == 0)
		stack_init(src, FALSE);
	else
	{
		src->data = src_next;
		src->info.head = src->data;
	}
	if (is_dst_a)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	swap(t_stack *src, t_bool is_a, t_bool is_all)
{
	t_list	*next_lst;

	if (src->info.len < 2)
		return ;
	next_lst = src->data->next->next;
	ft_lstadd_front(&src->data, src->data->next);
	src->data->next->next = next_lst;
	if (src->info.len == 2)
		src->info.tail = src->data->next;
	src->info.head = src->data;
	if (is_all)
		return ;
	if (is_a)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	swap_all(t_stack *src1, t_stack *src2)
{
	if (src1->info.len < 2 || src2->info.len < 2)
		return ;
	swap(src1, TRUE, TRUE);
	swap(src2, FALSE, TRUE);
	ft_putstr_fd("ss\n", 1);
}

void	rotate(t_stack *src, t_bool is_a, t_bool is_reverse, t_bool is_all)
{
	if (src->info.len < 2)
		return ;
	if (is_reverse)
	{
		src->info.tail = src->info.tail->prev;
		ft_lstadd_front(&src->data, src->info.tail->next);
		src->info.head = src->data;
		src->info.tail->next = 0;
	}
	else
	{
		src->data = src->data->next;
		src->info.tail->next = src->info.head;
		src->info.head->next = 0;
		src->info.tail = src->info.head;
		src->info.head = src->data;
	}
	if (is_all)
		return ;
	if (is_reverse)
		write(1, "r", 1);
	if (is_a)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rotate_all(t_stack *src1, t_stack *src2, t_bool is_reverse)
{
	if (src1->info.len < 2)
	{
		rotate(src1, TRUE, is_reverse, FALSE);
		return ;
	}
	if (src2->info.len < 2)
	{
		rotate(src2, FALSE, is_reverse, FALSE);
		return ;
	}
	rotate(src1, TRUE, is_reverse, TRUE);
	rotate(src2, FALSE, is_reverse, TRUE);
	if (is_reverse)
		ft_putstr_fd("rrr\n", 1);
	else
		ft_putstr_fd("rr\n", 1);
}
