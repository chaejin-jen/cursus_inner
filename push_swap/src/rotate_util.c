/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:05:12 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/02 19:11:25 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_all_size(t_stack *src1, t_stack *src2, int size)
{
	while (size--)
		rotate_all(src1, src2, ALL);
}

void	rotate_next(t_stack *src1, t_stack *src2, t_flag flag)
{
	swap(src1, flag);
	rotate_all(src1, src2, ALL_REV);
}

void	rotate_next_next(t_stack *src1, t_stack *src2, t_flag flag)
{
	push(src2, src1, !flag);
	swap(src2, !flag);
	rotate_all(src1, src2, ALL_REV);
}
