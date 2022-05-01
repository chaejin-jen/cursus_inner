/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:28:37 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/23 20:27:34 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack, t_list *pre)
{
	stack->data = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		print_error(pre);
	stack->data->content = (void *)2147483648;
	stack->data->next = 0;
	stack->data->prev = 0;
	stack->info.head = stack->data;
	stack->info.tail = stack->data;
	stack->info.null = 0;
	stack->info.size = 0;
}

void	stack_empty(t_stack *stack)
{
	stack->data = stack->info.null;
	stack->data->content = (void *)2147483648;
	stack->data->next = 0;
	stack->data->prev = 0;
	stack->info.head = stack->data;
	stack->info.tail = stack->data;
	stack->info.null = 0;
	stack->info.size = 0;
}

void	stack_add(t_stack *stack, t_list *data)
{
	if (stack->data->content == (void *)2147483648)
		stack->data->content = data->content;
	else
	{
		ft_lstadd_front(&stack->data, data);
		stack->info.head = stack->data;
	}
}
