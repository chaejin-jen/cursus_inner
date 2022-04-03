/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:35:53 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 18:24:09 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // 삭제하기
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef enum e_flag
{
	A = 0,
	B = 1,
	A_REV = 2,
	REV = 2,
	B_REV = 3,
	ALL = 4,
	ALL_REV = 6
}				t_flag;

typedef enum e_sort
{
	DESCENDING = 1,
	ASCENDING = 0,
	TOP = 0,
	MID = 1,
	BOT = 2
}				t_sort;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

typedef struct s_sort_op
{
	int		rr_size;
	t_sort	sort_loc;
	t_flag	sort_dst;
	t_sort	sort_order;
	t_sort	merge_loc;
	t_flag	merge_dst;
	t_sort	merge_order;
}				t_sort_op;

typedef struct s_stack_info
{
	t_list		*head;
	t_list		*tail;
	t_list		*null;
	int			size;
}				t_stack_info;

typedef struct s_stack
{
	t_list			*data;
	t_stack_info	info;
}				t_stack;

/* =========================  ======================== */
/* print_error.c */
void	print_error(t_list *lst);

/* test_print.c */
void	print_two_lst(t_stack *s1, t_stack *s2);
void	print_sort_op(t_sort_op *op, t_sort location);

/* make_stack.c */
t_stack	make_stack(int argc, char **argv);

/* stack.c */
void	stack_init(t_stack *stack);
void	stack_empty(t_stack *stack);
void	stack_add(t_stack *stack, t_list *data);

/* operate.c */
void	push(t_stack *dst, t_stack *src, t_flag flag);
void	swap(t_stack *src, t_flag flag);
void	swap_all(t_stack *src1, t_stack *src2);
void	rotate(t_stack *src, t_flag flag);
void	rotate_all(t_stack *src1, t_stack *src2, t_flag flag);

/* sort_set.c */
void	sort_op_init(t_sort_op *op);
void	sort_top_op_set(t_sort_op *new_op, t_sort_op *op);
void	sort_mid_op_set(t_sort_op *new_op, t_sort_op *op);
void	sort_bot_op_set(t_sort_op *new_op, t_sort_op *op);

/* sort.c */
void	sort(t_stack *a, t_stack *b, int size, t_sort_op op);

/* push_util.c */
void	push_size(t_stack *dst, t_stack *src, t_flag flag, int size);
void	push_next(t_stack *dst, t_stack *src, t_flag flag);
void	push_next_next(t_stack *dst, t_stack *src, t_flag flag);
void	push_tail(t_stack *dst, t_stack *src, t_flag flag);

/* rotate_util.c */
void	rotate_all_size(t_stack *src1, t_stack *src2, int size);
void	rotate_next(t_stack *dst, t_stack *src, t_flag flag);
void	rotate_next_next(t_stack *dst, t_stack *src, t_flag flag);

/* swap_util.c */
void	swap_third_second(t_stack *src, t_flag flag);
void	swap_first_third(t_stack *src, t_flag flag);

/* push_sort.c */
void	push_sort(t_stack *b, t_stack *a, int size, t_sort order);

/* rotate_sort.c */
void	rotate_sort(t_stack *a, t_stack *b, int size, t_sort order);

/* swap_sort.c */
void	swap_sort(t_stack *a, int size, t_sort order);

/* merge_util.c */
void	merge_num_init(t_stack *a, t_stack *b, long *num, t_flag merge_dst);
t_sort	get_merge_location(long *n, t_sort order);
t_sort	cmp_top_mid(t_stack *a, t_stack *b, t_sort_op *op);
t_sort	cmp_top_bot(t_stack *a, t_stack *b, t_sort_op *op);
t_sort	cmp_mid_bot(t_stack *a, t_stack *b, t_sort_op *op);

/* merge.c */
void	merge(t_stack *a, t_stack *b, int *len, t_sort_op *op);

/* utils.c */
void	free_pptr(void **pptr);
void	num_init(long *num, t_list *lst);

#endif
