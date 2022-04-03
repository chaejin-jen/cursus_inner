/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:47:26 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/02 17:02:11 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_size(t_stack *dst, t_stack *src, t_flag flag, int size)
{
	while (size--)
		push(dst, src, flag);
}

void	push_next(t_stack *dst, t_stack *src, t_flag flag)
{
	swap(src, !flag);
	push(dst, src, flag);
}

void	push_next_next(t_stack *dst, t_stack *src, t_flag flag)
{
	rotate(src, !flag);
	swap(src, !flag);
	push(dst, src, flag);
	rotate(src, !flag + REV);
}

void	push_tail(t_stack *dst, t_stack *src, t_flag flag)
{
	rotate(src, !flag + REV);
	push(dst, src, flag);
}
