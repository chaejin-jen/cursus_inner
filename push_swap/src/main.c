/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:14 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 18:29:26 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_sort_op	op;

	if (argc < 2)
		print_error(NULL);
	stack_init(&b);
	a = make_stack(argc, argv);
	// print_two_lst(&a, &b);
	sort_op_init(&op);
	sort(&a, &b, a.info.size, op);
	// push(&a, &b, A);
	// push(&b, &a, B);
	// swap(&a, A);
	// swap(&b, B);
	// rotate(&a, A);
	// rotate(&a, A_REV);
	// rotate(&b, B);
	// rotate(&b, B_REV);
	// rotate_all(&a, &b, ALL);
	// rotate_all(&a, &b, ALL_REV);
	// rotate(&a, A);
	//print_two_lst(&a, &b);
	ft_lstclear(&a.data, ft_del);
	free(b.data);
	return (0);
}
