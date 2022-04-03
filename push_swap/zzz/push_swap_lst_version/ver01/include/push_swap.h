/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:35:53 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/27 02:52:19 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h> // 삭제하기
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef enum	e_flag
{
	A = -1,
	B = 0,
	A_REV = 1,
	REV = 2,
	B_REV = 3,
	ALL = 4,
	ALL_REV = 6
}				t_flag;

typedef enum	e_sort
{
	DESCENDING = -1,
	ASCENDING = 0,
	TOP = 1,
	MIDDLE = 2,
	BOTTOM = 3,
}				t_sort;

typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

typedef struct	s_sort_info
{
	t_sort	location;
	//t_sort	target;
	//t_sort	sorce;
	t_sort	order;
	int		order;
	//t_list	*top;
	//t_list	*mid;
	//t_list	*bot;
	int		depth;
	int		loc_size;
	int		top_size;
	int		mid_size;
}				t_sort_info;

typedef struct	s_stack_info
{
	t_list		*head;
	t_list		*tail;
	t_list		*null;
	t_sort_info	sort;
	int			size;
}				t_stack_info;

typedef struct s_stack
{
	t_list			*data;
	t_stack_info	info;
}				t_stack;

/* print_error.c */
void	print_error(void);

/* test_print.c */
void	print_lst(t_list *lst);
void	print_two_lst(t_list *a, t_list *b);
void	print_info(t_stack_info info);
void	print_test(t_stack a, t_stack b);

void	argv_to_lst(t_stack *stack, int argc, char **argv);

/* stack.c */
void	stack_init(t_stack *stack, t_bool is_first_init);
void	stack_add(t_stack *stack, t_list *data);

/* operate.c */
void	push(t_stack *dst, t_stack *src, t_flag flag);
void	swap(t_stack *src, t_flag flag);
void	swap_all(t_stack *src1, t_stack *src2);
void	rotate(t_stack *src, t_flag flag);
void	rotate_all(t_stack *src1, t_stack *src2, t_flag flag);

/* sort.c */
void	sort_init(t_sort_info *info, int stack_size);
void	sort(t_stack *dst, t_stack *src, t_flag flag, t_sort_info *info);

/* push.c */
void	push_size(t_stack *dst, t_stack *src, t_flag flag, int size);
void	push_next(t_stack *dst, t_stack *src, t_flag flag);
void	push_tail(t_stack *dst, t_stack *src, t_flag flag);

/* push_three.c */
void	push_head_tail_next(t_stack *dst, t_stack *src, t_flag flag);
void	push_next_head_tail(t_stack *dst, t_stack *src, t_flag flag);
void	push_next_tail_head(t_stack *dst, t_stack *src, t_flag flag);
void	push_tail_head_next(t_stack *dst, t_stack *src, t_flag flag);
void	push_tail_next_head(t_stack *dst, t_stack *src, t_flag flag);

/* push_orders.c */
void	push_ascending(t_stack *dst, t_stack *src, t_flag flag);
void	push_descending(t_stack *dst, t_stack *src, t_flag flag);

#endif
