/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:35:53 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/25 03:13:22 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h> // 삭제하기
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

//# define A 1
//# define B 0
//# define REV 2
//# define ALL 4

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}			t_bool;

typedef struct s_sort_info
{
	//long	min1;
	//long	min2;
	//long	min3;
	//long	max1;
	//long	max2;
	//long	max3;
	//long	next_max;
	t_list	*loc_top;
	t_list	*loc_mid;
	t_list	*loc_bot;
	t_list	*top;
	t_list	*mid;
	t_list	*bot;
	int		div;
	int		sort_len;
}				t_sort_info;


typedef struct s_stack_info
{
	t_list *head;
	t_list *tail;
	t_list *null;
	int len;
}				t_stack_info;

typedef struct s_stack
{
	t_list *data;
	t_stack_info info;
} t_stack;

// sa, sb, ss, pa, p
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
void	push(t_stack *dst, t_stack *src, t_bool is_dst_a);
void	swap(t_stack *src, t_bool is_a, t_bool is_all);
void	swap_all(t_stack *src1, t_stack *src2);
void	rotate(t_stack *src, t_bool is_a, t_bool is_reverse, t_bool is_all);
void	rotate_all(t_stack *src1, t_stack *src2, t_bool is_reverse);


/* sort.c */
void	sort_init(t_sort_info *info, int len);
void	sort(t_stack *a, t_stack *b, t_sort_info *info);


void	push_max(t_stack *a, t_stack *b);
//void	push_min(t_stack *a, t_stack *b);


long	*put_1st_2nd_last(long first, long second, long last)

#endif
