/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:14 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 03:28:06 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		stack;

	if (argc < 2)
		print_error(NULL);
	stack = make_stack(argc, argv);
	sort(&stack, stack.info.size);
	ft_lstclear(&stack.data, ft_del);
	return (0);
}
