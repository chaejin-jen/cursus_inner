/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 05:53:41 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/26 22:00:46 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sort_info	*sort_new(t_sort_info *sort)
{
	t_sort_info *new;

	if (sort->top_size <= 3)
		return (0);
	new = (t_sort_info *)malloc(sizeof(t_sort_info));
	if (new == NULL)
		print_error();
	sort_init(new, );
	return (new);
}

void	sort_init(t_sort_info *sort, int stack_size)
{


	sort->status = TOP;
	sort->depth = 0;
	sort->top_size = (int)(stack_size / 3 + stack_size % 3);
	sort->mid_size = (int)(stack_size / 3);
	sort->next = add_sort(sort);
	if (sort->next == 0)
		return ;
}
