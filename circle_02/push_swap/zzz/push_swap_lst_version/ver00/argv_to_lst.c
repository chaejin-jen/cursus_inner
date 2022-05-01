/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:10:08 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/23 16:28:21 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_swap_atoi(const char *str)
{
	int	sign;
	int	tmp;
	int	sum;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	sum = 0;
	tmp = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = (sum * 10) + sign * (*str - '0');
		if (sum > 0 && tmp < 0)
			print_error();
		if (sum < 0 && tmp > 0)
			print_error();
		sum = tmp;
		str++;
	}
	return (sum);
}

static void	valid_content(t_list *lst, void *n)
{
	t_list	*cur_lst;

	if (n == 0)
		print_error();
	cur_lst = lst;
	while (cur_lst->next)
	{
		if (cur_lst->content == n)
			print_error();
		cur_lst = cur_lst->next;
	}
}

static void	lstadd_new(t_list **lst, void *n)
{
	t_list	*new_lst;

	if ((*lst)->content == 0)
		(*lst)->content = n;
	else
	{
		new_lst = ft_lstnew(n);
		if (!new_lst)
			print_error();
		ft_lstadd_front(lst, new_lst);
	}
}

void	argv_to_lst(t_stack *stack, int argc, char **argv)
{
	long	n;
	int		len;

	len = 0;
	stack->info.len = argc - 1;
	while (--argc)
	{
		n = ft_swap_atoi(argv[argc]);
		valid_content(stack->data, (void *) n);
		lstadd_new(&stack->data, (void *) n);
	}
	stack->info.head = stack->data;
}
