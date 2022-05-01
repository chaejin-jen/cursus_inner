/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:16:27 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/06 13:08:07 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef enum e_flags
{ 
	flag_minus = 1 << 0,
	flag_zero = 1 << 1,
	flag_space = 1 << 2,
	flag_dot = 1 << 3,
	flag_plus = 1 << 4,
	flag_hash = 1 << 5
}			t_flags;

typedef struct s_print_info
{
	char			type;
	unsigned int	flag;
	unsigned int	width;
	unsigned int	preci;
	int				p_len;
}				t_print_info;

/*================*/
void	print_info_init(t_print_info *p_info);
int		set_p_info(t_print_info *p_info, const char *fmt);

/*================*/
char	*ft_strchr(const char *s, int c);
int		strchr_index(const char *s, int c);
char	*malloc_end_null(size_t count, size_t size);

/*================*/
int		print_d(t_print_info p_info, int n);
int		print_u(t_print_info p_info, unsigned int u_i);
int		print_c(t_print_info p_info, int c);
int		print_s(t_print_info p_info, char *s);
int		print_p(t_print_info p_info, void *addr);
/*================*/
int		ft_printf(const char *fmt, ...);

#endif