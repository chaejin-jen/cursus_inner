/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_jasong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:12:02 by jasong            #+#    #+#             */
/*   Updated: 2022/03/28 23:09:30 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    repeat_rr(t_topbot *a, t_topbot *b, int *len, int flag)
{
	int     tmp[3];
	tmp[0] = len[0];
	tmp[1] = len[1];
	tmp[2] = len[2];
	if (flag == A)
	{
		while (tmp[RIGHT]--)
		{
			rotate_both(a, b);
			tmp[LEFT]--;
		}
		while (tmp[LEFT]--)
			rotate(a, RA);
	}
	else
	{
		while (tmp[RIGHT]--)
			rotate_both(a, b);
	}
}
void    send_piece(t_topbot *src, t_topbot *dest, int size)
{
	while (size)
	{
		push(src, dest, dest->s_flag);
		size--;
	}
}
void    sort_to_a(t_topbot *a, t_topbot *b, int size, int order)
{
	int     len[3];
	if (size <= 3)
	{
		sort_piece(a, size, order);
		return ;
	}
	else
	{
		len[RIGHT] = size / 3;
		len[MID] = size / 3;
		len[LEFT] = size / 3 + size % 3;
		sort_to_b(a, b, len[RIGHT], !order);
		sort_to_b(a, b, len[MID], order);
		sort_to_a(a, b, len[LEFT], order);
		repeat_rr(a, b, len, A);
		merge_to_a(a, b, len, order);
	}
}
void    sort_to_b(t_topbot *a, t_topbot *b, int size, int order)
{
	int     len[3];
	if (size <= 3)
	{
		sort_piece(a, size, !order);
		send_piece(a, b, size);
		return ;
	}
	else
	{
		len[RIGHT] = size / 3;
		len[MID] = size / 3;
		len[LEFT] = size / 3 + size % 3;
		sort_to_b(a, b, len[RIGHT], order);
		sort_to_a(a, b, len[MID], order);
		repeat_rr(a, b, len, B);
		sort_to_a(a, b, len[LEFT], !order);
		merge_to_b(a, b, len, order);
	}
}
void    sort_all(t_topbot *a, t_topbot *b, int size)
{
	int	len[3];

	if (!a || !b)
		common_error();
	if (check_sorted(a, size, ASCEND))
		return ;
	if (size <= 3)
		sort_piece(a, size, ASCEND);
	else
	{
		len[RIGHT] = size / 3;
		len[MID] = size / 3;
		len[LEFT] = size / 3 + size % 3;
		sort_to_b(a, b, len[RIGHT], ASCEND);
		sort_to_b(a, b, len[MID], DESCEND);
		sort_to_a(a, b, len[LEFT], ASCEND);
		merge_all(a, b, len, size);
	}
}
