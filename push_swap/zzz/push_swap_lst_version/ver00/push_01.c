/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:04:31 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/25 04:23:26 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** first_push, second_push, third_push, all_push
** 더 큰 맥스가 들어올 때 마다 남은 작은 값 push 하고, second push... third push...
** all_push 가 끝나면, a 스택에 정렬 완료
** [pb] - max1 짜잘이(max2 나오기 전까지).. max2, rrb로 max1 올리고 짜잘이(max3 나오기 전까지), max3 올리고 짜잘이(새로운 max 나올때까지)
** [pa] - max3 까지
** [rr] max3, max1 까지 (갯수 안 맞으면, 남는 부위 ra 또는 rb)
** [pa/rrb-pa/rra] max1,2,3 큰것부터 차곡차고
** 계속 반복.... all_push 될 때 까지!
** 목표! input 100에 700번, input 500에 5000번
*/

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

void	push_head_next(t_stack *dst, t_stack *src, t_flag flag)
{
	push(dst, src, flag);
	push(dst, src, flag);
}

void	push_b_asc(t_stack *a, t_stack *b, int push_len)
{
	long	n[3];

	if (push_len == 1)
		push(b, a, B);
	else if (push_len == 2)
	{
		if ((long)src->data->content > (long)src->data->next->content)
			swap(a, A);
		push(b, a, B);
		push(b, a, B);
	}
	n = put_1st_2nd_last(src->data->content, src->data->next->content, src->info.tail->content);
	if (n[0] > n[1] && n[0] > n[2])
	{
		push(b, a, B);
		if (n[1] < n[2])
			rotate(a, A_REV);
	}
	else if (n[1] > n[0] && n[1] > n[2])
	{
		swap(a, A);
		push(b, a, B);
		if (n[0] < n[2])
			rotate(a, A_REV);
	}
	else
	{
		rotate(a, A_REV);
		push(b, a, B);
		if (n[0] < n[1])
			swap(a, A);
	}
	push(b, a, B);
	push(b, a, B);
}

void	push_desc(t_stack *a, t_stack *b, int push_len)
{

}

void	push_max(t_stack *a, t_stack *b)
{
	long	first;
	long	second;
	long	last;

	if (a->info.len == 1)
	{
		push(b, a, B);
		return ;
	}
	else if (a->info.len == 2)
	{
		if (a->info.head->content > a->info.tail->content)
			push(b, a, B);
		else
		{
			swap(a, A);
			push(b, a, B);
		}
		return ;
	}
	first = (long)a->info.head->content;
	second = (long)a->info.head->next->content;
	last = (long)a->info.tail->content;
	if (first > second && first > last)
		push(b, a, B);
	else if (second > first && second > last)
	{
		swap(a, A);
		push(b, a, B);
	}
	else
	{
		rotate(a, A_REV);
		push(b, a, B);
	}
}

void	push_min(t_stack *a, t_stack *b)
{
	long	first;
	long	second;
	long	last;

	if (a->info.len == 1)
	{
		push(b, a, B);
		return ;
	}
	else if (a->info.len == 2)
	{
		if (a->info.head->content < a->info.tail->content)
			push(b, a, B);
		else
		{
			swap(a, A);
			push(b, a, B);
		}
		return ;
	}
	first = (long)a->info.head->content;
	second = (long)a->info.head->next->content;
	last = (long)a->info.tail->content;
	if (first < second && first < last)
		push(b, a, B);
	else if (second < first && second < last)
	{
		swap(a, A);
		push(b, a, B);
	}
	else
	{
		rotate(a, A_REV);
		push(b, a, B);
	}
}

void	push_asc(t_stack *a, t_stack *b)
{

}

void	push_desc(t_stack *a, t_stack *b)
{

}
