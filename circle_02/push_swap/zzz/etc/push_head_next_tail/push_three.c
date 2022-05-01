/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 04:44:37 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/26 06:12:15 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_head_tail_next(t_stack *dst, t_stack *src, t_flag flag)
{
	push(dst, src, flag);
	push_tail(dst, src, flag);
	push(dst, src, flag);
}
void push_next_head_tail(t_stack *dst, t_stack *src, t_flag flag)
{
	push_next(dst, src, flag);
	push(dst, src, flag);
	push_tail(dst, src, flag);
}
void push_next_tail_head(t_stack *dst, t_stack *src, t_flag flag)
{
	push_next(dst, src, flag);
	push_tail(dst, src, flag);
	push(dst, src, flag);
}
void push_tail_head_next(t_stack *dst, t_stack *src, t_flag flag)
{
	push_tail(dst, src, flag);
	push(dst, src, flag);
	push(dst, src, flag);
}

void push_tail_next_head(t_stack *dst, t_stack *src, t_flag flag)
{
	push_tail(dst, src, flag);
	push_next(dst, src, flag);
	push(dst, src, flag);
}
