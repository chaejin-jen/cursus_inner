/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:41:49 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/02 04:19:38 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_print(const char *fmt, va_list *arg_ptr, int *write_byte)
{
	if (*fmt == 'c')
		*write_byte += print_c(va_arg(*arg_ptr, int));
	else if (*fmt == 's')
		*write_byte += print_s(va_arg(*arg_ptr, char *));
	else if (*fmt == 'i' || *fmt == 'd')
		*write_byte += print_d(va_arg(*arg_ptr, int));
	else if (*fmt == 'u')
		*write_byte += print_u(va_arg(*arg_ptr, int));
	else if (*fmt == 'x')
		*write_byte += print_x_lower(va_arg(*arg_ptr, unsigned int));
	else if (*fmt == 'X')
		*write_byte += print_x_upper(va_arg(*arg_ptr, unsigned int));
	else if (*fmt == 'p')
		*write_byte += print_p(va_arg(*arg_ptr, void *));
	else if (*fmt == '%')
		*write_byte += write(1, "%", 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg_ptr;
	int		write_byte;

	write_byte = 0;
	va_start(arg_ptr, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			do_print(++fmt, &arg_ptr, &write_byte);
		else
			write_byte += write(1, fmt, 1);
		fmt++;
	}
	va_end(arg_ptr);
	return (write_byte);
}
