/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:10:08 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 19:59:26 by chaejkim         ###   ########.fr       */
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
			return (0);
		if (sum < 0 && tmp > 0)
			return (0);
		sum = tmp;
		str++;
	}
	return (sum);
}

static void	valid_content(t_list *lst, void *n)
{
	t_list	*cur_lst;

	if (n == 0)
		print_error(lst);
	cur_lst = lst;
	while (cur_lst)
	{
		if (cur_lst->content == n)
			print_error(lst);
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
			print_error(*lst);
		ft_lstadd_front(lst, new_lst);
	}
}

static void	put_argv_to_stack(t_list **data, char *arg, int *size)
{
	char			**array;
	long			n;
	unsigned int	j;

	j = 0;
	array = ft_split(arg, ' ');
	while (array[j])
		j++;
	while (j--)
	{
		n = ft_swap_atoi(array[j]);
		valid_content(*data, (void *)n);
		(*size)++;
		lstadd_new(data, (void *)n);
	}
	free_pptr((void **)array);
}

t_stack	make_stack(int argc, char **argv)
{
	t_stack	stack;
	int		size;

	size = 0;
	stack_init(&stack);
	while (--argc)
		put_argv_to_stack(&stack.data, argv[argc], &stack.info.size);
	stack.info.head = stack.data;
	return (stack);
}
