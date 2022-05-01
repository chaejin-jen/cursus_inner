/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:47:26 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/27 02:08:56 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_next(t_stack *dst, t_stack *src, t_flag flag)
{
	swap(src, flag);
	push(dst, src, flag);
}

void	push_tail(t_stack *dst, t_stack *src, t_flag flag)
{
	rotate(src, flag + REV);
	push(dst, src, flag);
}

void	push_size(t_stack *dst, t_stack *src, t_flag flag, int size)
{
	while (size--)
		push(dst, src, flag);
}

void	reverse_rotate(t_stack *dst, t_stack *src, int size)
{
	while (sieze--)
		rotate_all(dst, src, ALL_REV);
}

