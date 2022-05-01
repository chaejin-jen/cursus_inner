/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 05:53:41 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/27 03:00:15 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	push_small_sort(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	if (info->loc_size == 1)
	{
		push(dst, src, flag);
		return ;
	}
	if (info->order == ASCENDING)
	{
		if ((long)src->data->content > (long)src->data->next->content)
			swap(dst, !flag);
	}
	else
	{
		if ((long)src->data->content > (long)src->data->next->content)
			swap(dst, !flag);
	}
	push_size(dst, src, !flag, 2);
}

void	swap_small_sort(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	if (info->loc_size == 1)
	{
		if (info->location == TOP)
			return ;
		rotate_all(dst, src, flag);
		return ;
	}
	if (info->order == ASCENDING)
	{
		if ((long)src->data->content > (long)src->data->next->content)
			swap(dst, !flag);
	}
	else
	{
		if ((long)src->data->content > (long)src->data->next->content)
			swap(dst, !flag);
	}
	rotate_all(dst, src, flag);
	rotate_all(dst, src, flag);
}

void	sort_top(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	if (info->size > 3)
		sort(dst, src, flag, info)
	if (src->info.sort->loc_size < 3)
	{
		push_small_sort(dst, src, flag, info);
		return;
	}
	if (flag == A)
		push_sort(dst, src, flag, !order)
	else
		push_sort(dst, src, flag, order)
}

void	sort_middle(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	if (info->size > 3)
	{
		sort(dst, src, flag, info)
	}
	if (src->info.sort->loc_size < 3)
	{
		if (flag == A)
			push_small_sort(dst, src, flag, info);
		else
		{
			swap_small_sort(dst, src, flag, info);
			// sort_top 이 b 아래로 다 안 간 경우 처리 필요
		}
		return;
	}
	if (flag == A)
		push_sort(dst, src, flag, order);
	else
		swap_sort(dst, src, flag, bottom);
}

void	sort_bottom(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	if (info->size > 3)
		sort(dst, src, flag, info)
	if (src->info.sort->loc_size < 3)
		swap_small_sort(dst, src, flag, info);
	if (flag == A)
		swap_sort(dst, src, flag, bottom);
	else
		swap_sort(dst, src, flag, top);
}
*/

static void	sort_top(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	if (info->loc_size > 3)
		sort(dst, src, flag, info);
	push_sort(src, dst, !flag, info->order);
}

static void	sort_middle(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	if (info->loc_size <= 3)
	{
		swap_sort(dst, src, flag, info->order);
		return ;
	}
	sort(dst, src, flag, info);
}

static void	sort_bottom(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	if (info->loc_size > 3)
		sort(dst, src, flag, info);
	info->order = !info->order;
	if (flag == A)
		push_sort(src, dst, !flag, info);
	else
		swap_sort(dst, src, flag, info);
	info->order = !info->order;
}

static void	merge_top_mid_bot(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{

}

void	sort(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info)
{
	sort_top(dst, src, flag, info);
	sort_mid(dst, src, flag, info);
	reverse_rotate(dst, src, info->loc_size);
	sort_bot(dst, src, flag, info);
	merge_top_mid_bot(dst, src, flag, info);
}
