/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:14 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/25 03:57:20 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	t_sort_info info;
	t_flag		flag;

	if (argc < 2)
		print_error();
	stack_init(&a, TRUE);
	stack_init(&b, TRUE);
	argv_to_lst(&a, argc, argv);
	//sort_init(&info, argc - 1);
	//print_two_lst(a.data, b.data);
	//sort(&a, &b, &info);

	/* rra */
	//rotate(&a, A, NOT_REV, NOT_ALL);
	//rotate(&a, A, NOT_REV, NOT_ALL);

	//push(&b, &a, B);
	//print_two_lst(a.data, b.data);

		write(1, "a_init\n", 7);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_init\n", 7);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n0==========================", 27);
	swap(&a, A);
	rotate(&a, A);
	print_test(a, b);

	write(1, "\n1==========================", 27);
	rotate(&a, A);
	//push(&b, &a, B);
	print_test(a, b);

	write(1, "\n2==========================", 27);
	rotate(&a, A);
	//swap(&a, A);
	// push(&b, &a, B);
	print_test(a, b);

	write(1, "\n3==========================", 27);
	rotate(&a, A);
	//push(&b, &a, B);
	//push(&b, &a, B);
	print_test(a, b);

	write(1, "\n4==========================", 27);
	rotate(&a, A);
	swap(&a, A);
	// printf("tail->next %d\n", a.info.tail->next);
	// push(&b, &a, B);
	print_test(a, b);

	write(1, "\n5==========================", 27);
	//swap_all(&a, &b);
	push(&b, &a, B);
	print_test(a, b);

	write(1, "\n6==========================",27);
	push(&b, &a, B);
	print_test(a, b);

	write(1, "\n7==========================",27);
	push(&b, &a, B);
	push(&b, &a, B);
	push(&b, &a, B);
	print_test(a, b);

	write(1, "\n8==========================",27);
	push(&b, &a, B);
	print_test(a, b);

	write(1, "\n1==========================", 27);
	push(&a, &b, A);
	print_test(a, b);

	write(1, "\n2==========================", 27);
	swap_all(&a, &b);
	// push(&a, &b, A);
	print_test(a, b);

	write(1, "\n3==========================", 27);
	push(&a, &b, A);
	print_test(a, b);

	write(1, "\n4==========================", 27);
	push(&a, &b, A);
	print_test(a, b);

	write(1, "\n5==========================", 27);
	push(&a, &b, A);
	print_test(a, b);

	write(1, "\n6==========================", 27);
	push(&a, &b, A);
	print_test(a, b);

	write(1, "\n7==========================", 27);
	push(&a, &b, A);
	print_test(a, b);

	write(1, "\n8==========================", 27);
	push(&a, &b, A);
	print_test(a, b);

	print_two_lst(a.data, b.data);
	push(&b, &a, B);
	rotate(&a, A);
	print_two_lst(a.data, b.data);
	push(&b, &a, B);
	rotate(&a, A);
	print_two_lst(a.data, b.data);
}
