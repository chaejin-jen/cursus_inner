/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:16:27 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/02 03:39:39 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		print_d(int n);
int		print_u(unsigned int u_n);
int		print_x_lower(unsigned int u_n);
int		print_x_upper(unsigned int u_n);
int		print_c(int c);
int		print_s(char *s);
int		print_p(void *addr);
int		ft_printf(const char *fmt, ...);

#endif