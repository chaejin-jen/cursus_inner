/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:47:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/29 02:14:46 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_third_second(t_stack *src, t_flag flag)
{
	rotate(src, flag);
	swap(src, flag);
	rotate(src, flag + REV);
}

void	swap_first_third(t_stack *src, t_flag flag)
{
	rotate(src, flag);
	swap(src, flag);
	rotate(src, flag + REV);
}

/*
void	swap(t_stack *dst, t_stack *src, int size)
{
	while (size--)
		swap_all(dst, src, ALL);
}



void	swap(t_stack *src1, t_stack *src2, t_flag flag)
{
	push(src2, src1, !flag);
	swap(src2, !flag);
	rotate_all(src1, src2, ALL_REV);
}
*/
