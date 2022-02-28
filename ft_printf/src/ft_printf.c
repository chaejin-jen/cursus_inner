/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:41:49 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/06 17:16:54 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	do_print(const char fmt, va_list *arg_ptr)
{
	int	p_len;

	p_len = 0;
	if (fmt == 'c')
		p_len += print_c(va_arg(*arg_ptr, int));
	else if (fmt == 's')
		p_len += print_s(va_arg(*arg_ptr, char *));
	else if (fmt == 'i' || fmt == 'd')
		p_len += print_d(va_arg(*arg_ptr, int));
	else if (fmt == 'u' || fmt == 'x' || fmt == 'X')
		p_len += print_u(fmt, va_arg(*arg_ptr, unsigned int));
	else if (fmt == 'p')
		p_len += print_p(va_arg(*arg_ptr, void *));
	else if (fmt == '%')
		p_len += write(1, "%", 1);
	return (p_len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg_ptr;
	int		f_i;
	int		p_len;

	p_len = 0;
	va_start(arg_ptr, fmt);
	while (*fmt)
	{
		f_i = strchr_index(fmt, '%');
		if (f_i)
		{
			p_len += write(1, fmt, f_i);
			fmt += f_i;
		}
		else
		{
			p_len += do_print(*++fmt, &arg_ptr);
			fmt++;
		}
	}
	va_end(arg_ptr);
	return (p_len);
}
