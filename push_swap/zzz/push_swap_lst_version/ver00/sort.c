/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 05:53:41 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/25 03:08:45 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_init(t_sort_info *info, int len)
{
	info->min1 = 0;
	info->min2 = 0;
	info->min3 = 0;
	info->max1 = 0;
	info->max2 = 0;
	info->next_max = 0;
	info->sort_len = len;
}

void	sort(t_stack *a, t_stack *b, t_sort_info *info)
{
	while (info->sort_len)
	{
		push_asc(a, b, len);
		push_desc(a, b, len);
	}
}
