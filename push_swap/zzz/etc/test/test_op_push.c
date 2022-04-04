/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:14 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/20 01:20:37 by chaejkim         ###   ########.fr       */
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

	write(1, "\n1==========================", 27);
	push(&a, &b, FALSE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n2==========================", 27);
	push(&a, &b, FALSE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n3==========================",27);
	push(&a, &b, FALSE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n4==========================",27);
	push(&a, &b, FALSE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n5==========================",27);
	push(&a, &b, FALSE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n6==========================",27);
	push(&a, &b, FALSE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n7==========================",27);
	push(&a, &b, FALSE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n8==========================",27);
	push(&a, &b, FALSE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n1==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n2==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n3==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n4==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n5==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n6==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n7==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n8==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);

	write(1, "\n2==========================",27);
	push(&b, &a, TRUE);
	write(1, "a_stack\n", 8);
	print_lst(a.data);
	print_info(a.info);
	write(1, "b_stack\n", 8);
	print_lst(b.data);
	print_info(b.info);
}
