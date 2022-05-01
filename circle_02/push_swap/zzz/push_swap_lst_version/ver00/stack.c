/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:28:37 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/23 16:25:23 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack, t_bool is_first_init)
{
	if (is_first_init)
	{
		stack->data = (t_list *)malloc(sizeof(t_list));
		if (!stack)
			print_error();
	}
	else
		stack->data = stack->info.null;
	stack->data->content = 0;
	stack->data->next = 0;
	stack->info.head = stack->data;
	stack->info.tail = stack->data;
	stack->info.null = 0;
	stack->info.len = 0;
}

void	stack_add(t_stack *stack, t_list *data)
{
	if (stack->data->content == 0)
	{
		stack->data->content = data->content;
		stack->data->next = 0;
	}
	else
		ft_lstadd_front(&stack->data, data);
}
