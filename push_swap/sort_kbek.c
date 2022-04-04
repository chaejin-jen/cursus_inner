/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_kbek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:42:43 by kbaek             #+#    #+#             */
/*   Updated: 2022/03/28 23:09:32 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	repeat_rr(list *plist, int len)
{
	int	i;
	i = -1;
	while (++i < len)
		rr(plist);
}
void	sort_skip(list *plist, int size, int order)
{
	int	len[3];
	if (size <= 3)
	{
		except_sort_skip(plist, size, order);
		return ;
	}
	len[RIGHT] = size / 3;
	len[MID] = size / 3;
	len[LEFT] = size / 3 + size % 3;
	sort_skip(plist, len[RIGHT], order);
	sort_fix(plist, len[MID], !order);
	repeat_rr(plist, len[MID]);
	sort_fix(plist, len[LEFT], order);
	merge_to_b(plist, len, order);
}
void	sort_fix(list *plist, int size, int order)
{
	int	len[3];
	if (check_already_sorted(plist, size, order))
		return ;
	if (size <= 3)
	{
		except_sort_fix(plist, size, order);
		return ;
	}
	len[RIGHT] = size / 3 + size % 3;
	len[MID] = size / 3;
	len[LEFT] = size / 3;
	sort_skip(plist, len[RIGHT], order);
	sort_skip(plist, len[MID], !order);
	sort_fix(plist, len[LEFT], order);
	repeat_rr(plist, len[MID]);
	merge_to_a(plist, len, order);
}
void	list_sort(list *plist)
{
	int	len[3];

	if (plist->numOfData == 2)
		return (sa(plist));
	else if (plist->numOfData == 3)
		return (except_sort_fix(plist, 3, DESCEND));
	len[LEFT] = plist->numOfData / 3 + plist->numOfData % 3;
	len[MID] = plist->numOfData / 3;
	len[RIGHT] = plist->numOfData / 3;
	sort_skip(plist, len[RIGHT], ASCEND);
	sort_skip(plist, len[MID], DESCEND);
	sort_fix(plist, len[LEFT], DESCEND);
	swap_number(&len[MID], &len[RIGHT]);
	merge_to_a(plist, len, DESCEND);
}
