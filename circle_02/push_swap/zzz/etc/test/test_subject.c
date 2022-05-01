/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:35:14 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/23 17:06:33 by chaejkim         ###   ########.fr       */
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
	print_two_lst(a.data, b.data);

	//make fclean && make && ./push_swap 2 1 3 6 5 8
	swap(&a, TRUE, FALSE);
	print_two_lst(a.data, b.data);
	push(&a, &b, FALSE);
	print_two_lst(a.data, b.data);
	push(&a, &b, FALSE);
	print_two_lst(a.data, b.data);
	push(&a, &b, FALSE);
	print_two_lst(a.data, b.data);
	swap(&a, TRUE, FALSE);
	print_two_lst(a.data, b.data);
	push(&b, &a, TRUE);
	print_two_lst(a.data, b.data);
	push(&b, &a, TRUE);
	print_two_lst(a.data, b.data);
	push(&b, &a, TRUE);
	print_two_lst(a.data, b.data);

	//ft_lstclear(&a.data, free);
	//ft_lstclear(&b.data, free);
}
