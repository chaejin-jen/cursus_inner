/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:51:05 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 17:51:03 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src, t_flag flag)
{
	t_list	*src_next;

	if (src->info.size == 0)
		return ;
	src_next = src->data->next;
	if (++(dst->info.size) == 1)
	{
		src->info.null = src->data;
		dst->info.null = src->data;
	}
	stack_add(dst, src->data);
	if (--(src->info.size) == 0)
		stack_empty(src);
	else
	{
		src->data = src_next;
		src->data->prev = 0;
		src->info.head = src->data;
	}
	if (flag == A)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	swap(t_stack *src, t_flag flag)
{
	t_list	*next_lst;

	if (src->info.size < 2)
		return ;
	next_lst = src->data->next->next;
	ft_lstadd_front(&src->data, src->data->next);
	src->data->next->next = next_lst;
	if (src->info.size == 2)
		src->info.tail = src->data->next;
	src->info.head = src->data;
	if (flag == ALL)
		return ;
	if (flag == A)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	swap_all(t_stack *src1, t_stack *src2)
{
	if (src1->info.size < 2 || src2->info.size < 2)
		return ;
	swap(src1, ALL);
	swap(src2, ALL);
	ft_putstr_fd("ss\n", 1);
}

void	rotate(t_stack *src, t_flag flag)
{
	if (src->info.size < 2)
		return ;
	if (flag >= REV && flag != ALL)
	{
		src->info.tail = src->info.tail->prev;
		ft_lstadd_front(&src->data, src->info.tail->next);
		src->info.head = src->data;
		src->info.tail->next = 0;
	}
	else
	{
		src->data = src->data->next;
		ft_lstadd_back(&src->data, src->info.head);
		src->info.tail = src->info.head;
		src->info.head = src->data;
		src->info.head->prev = 0;
	}
	if (flag >= ALL)
		return ;
	if (flag >= A_REV)
		write(1, "r", 1);
	if (flag == A || flag == A_REV)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rotate_all(t_stack *src1, t_stack *src2, t_flag flag)
{
	if (src1->info.size < 2)
	{
		rotate(src2, B);
		return ;
	}
	if (src2->info.size < 2)
	{
		rotate(src1, A);
		return ;
	}
	rotate(src1, flag);
	rotate(src2, flag);
	if (flag == ALL_REV)
		ft_putstr_fd("rrr\n", 1);
	else
		ft_putstr_fd("rr\n", 1);
}
