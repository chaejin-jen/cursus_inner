/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:16:27 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/13 14:44:25 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*================*/
int		strchr_index(const char *s, int c);
char	*malloc_end_null(size_t count, size_t size);

/*================*/
int		print_d(int n);
int		print_u(char type, unsigned int u_i);
int		print_c(int c);
int		print_s(char *s);
int		print_p(void *addr);
/*================*/
int		ft_printf(const char *fmt, ...);

#endif