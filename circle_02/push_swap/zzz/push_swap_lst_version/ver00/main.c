/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:14 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/25 03:53:20 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	t_sort_info info;

	if (argc < 2)
		print_error();
	stack_init(&a, TRUE);
	stack_init(&b, TRUE);
	argv_to_lst(&a, argc, argv);
	sort_init(&info, argc - 1);
	print_two_lst(a.data, b.data);
	sort(&a, &b, &info);

	/* rra */
	//rotate(&a, A, NOT_REV, NOT_ALL);
	//rotate(&a, A, NOT_REV, NOT_ALL);

	//push(&a, &b, FALSE);
	//print_two_lst(a.data, b.data);

	print_two_lst(a.data, b.data);
}
