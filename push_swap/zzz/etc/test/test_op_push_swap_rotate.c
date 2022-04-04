/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_op_push_swap_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:14 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/24 00:46:38 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;

	if (argc < 2)
		print_error();
	stack_init(&a, TRUE);
	stack_init(&b, TRUE);
	argv_to_lst(&a, argc, argv);

	write(1, "a_init\n", 7);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_init\n", 7);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n0==========================", 27);
	swap(&a, TRUE, FALSE);
	rotate(&a, TRUE, FALSE, FALSE);
	print_test(a, b);

	write(1, "\n1==========================", 27);
	rotate(&a, TRUE, FALSE, FALSE);
	//push(&a, &b, FALSE);
	print_test(a, b);

	write(1, "\n2==========================", 27);
	rotate(&a, TRUE, FALSE, FALSE);
	//swap(&a, TRUE, FALSE);
	// push(&a, &b, FALSE);
	print_test(a, b);

	write(1, "\n3==========================", 27);
	rotate(&a, TRUE, FALSE, FALSE);
	//push(&a, &b, FALSE);
	//push(&a, &b, FALSE);
	print_test(a, b);

	write(1, "\n4==========================", 27);
	rotate(&a, TRUE, FALSE, FALSE);
	swap(&a, TRUE, FALSE);
	// printf("tail->next %d\n", a.info.tail->next);
	// push(&a, &b, FALSE);
	print_test(a, b);

	write(1, "\n5==========================", 27);
	//swap_all(&a, &b);
	push(&a, &b, FALSE);
	print_test(a, b);

	write(1, "\n6==========================",27);
	push(&a, &b, FALSE);
	print_test(a, b);

	write(1, "\n7==========================",27);
	push(&a, &b, FALSE);
	push(&a, &b, FALSE);
	push(&a, &b, FALSE);
	print_test(a, b);

	write(1, "\n8==========================",27);
	push(&a, &b, FALSE);
	print_test(a, b);

	write(1, "\n1==========================", 27);
	push(&b, &a, TRUE);
	print_test(a, b);

	write(1, "\n2==========================", 27);
	swap_all(&a, &b);
	// push(&b, &a, TRUE);
	print_test(a, b);

	write(1, "\n3==========================", 27);
	push(&b, &a, TRUE);
	print_test(a, b);

	write(1, "\n4==========================", 27);
	push(&b, &a, TRUE);
	print_test(a, b);

	write(1, "\n5==========================", 27);
	push(&b, &a, TRUE);
	print_test(a, b);

	write(1, "\n6==========================", 27);
	push(&b, &a, TRUE);
	print_test(a, b);

	write(1, "\n7==========================", 27);
	push(&b, &a, TRUE);
	print_test(a, b);

	write(1, "\n8==========================", 27);
	push(&b, &a, TRUE);
	print_test(a, b);

	print_two_lst(a.data, b.data);
	push(&a, &b, FALSE);
	rotate(&a, TRUE, FALSE, FALSE);
	print_two_lst(a.data, b.data);
	push(&a, &b, FALSE);
	rotate(&a, TRUE, FALSE, FALSE);
	print_two_lst(a.data, b.data);
}
