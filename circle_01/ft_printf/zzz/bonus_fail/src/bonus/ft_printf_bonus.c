/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:41:49 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/18 01:35:35 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_fmt(const char fmt, va_list *arg_ptr, t_print_info *p_info)
{
	p_info->type = fmt;
	if (fmt == 'c')
		p_info->p_len += print_c(*p_info, va_arg(*arg_ptr, int));
	else if (fmt == 's')
		p_info->p_len += print_s(*p_info, va_arg(*arg_ptr, char *));
	else if (fmt == 'i' || fmt == 'd')
		p_info->p_len += print_d(*p_info, va_arg(*arg_ptr, int));
	else if (fmt == 'u' || fmt == 'x' || fmt == 'X')
		p_info->p_len += print_u(*p_info, va_arg(*arg_ptr, unsigned int));
	else if (fmt == 'p')
		p_info->p_len += print_p(*p_info, va_arg(*arg_ptr, void *));
	else if (fmt == '%')
		p_info->p_len += write(1, "%", 1);
}


static void	do_print(const char *fmt, va_list *arg_ptr, t_print_info *p_info)
{
	int	f_i;

	while (*fmt)
	{
		f_i = strchr_index(fmt, '%');
		if (f_i)
		{
			p_info->p_len += write(1, fmt, f_i);
			fmt += f_i;
		}
		else
		{
			fmt++;
			while (!ft_strchr("csiduxXp%", *fmt))
			{
				f_i = set_p_info(p_info, fmt);
				fmt += f_i;
			}
			print_fmt(*fmt, arg_ptr, p_info);
			fmt++;
		}
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg_ptr;
	t_print_info	p_info;

	print_info_init(&p_info);
	va_start(arg_ptr, fmt);
	do_print(fmt, &arg_ptr, &p_info);
	va_end(arg_ptr);
	return (p_info.p_len);
}
