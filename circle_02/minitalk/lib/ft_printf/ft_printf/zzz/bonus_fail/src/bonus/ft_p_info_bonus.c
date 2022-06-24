/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:58:44 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/18 01:18:16 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_info_init(t_print_info *p_info)
{
	p_info->type = 0;
	p_info->flag = 0;
	p_info->width = 0;
	p_info->preci = 0;
	p_info->p_len = 0;
}

static void	flag_exception(t_print_info *p_info, int depen_flag, int check_flag)
{
	if (p_info->flag & check_flag)
		p_info->flag &= ~depen_flag;
	else
		p_info->flag |= depen_flag;
}

static int	set_width_preci(t_print_info *p_info, int flag, const char *fmt)
{
	int	f_i;

	f_i = 0;
	if (flag)
	{
		p_info->flag |= flag;
		while (fmt[f_i] >= '0' || fmt[f_i] <= '9')
		{
			p_info->preci = (p_info->preci * 10) + (fmt[f_i] - '0');
			f_i++;
		}
		return (p_info->preci);
	}
	while (fmt[f_i] > '0' || fmt[f_i] <= '9')
	{
		p_info->width = (p_info->width * 10) + (fmt[f_i] - '0');
		fmt++;	
	}
	return (p_info->width);
}

int	set_p_info(t_print_info *p_info, const char *fmt)
{
	int	f_i;

	f_i = 1;
	if (*fmt == '-')
		p_info->flag |= flag_minus;
	if (*fmt == '0')
		flag_exception(p_info, flag_zero, flag_minus);
	if (*fmt == ' ')
		flag_exception(p_info, flag_space, flag_plus);
	if (*fmt == '.' && !(p_info->flag & flag_dot))
		f_i = set_width_preci(p_info, flag_dot, fmt);
	if (*fmt == '+')
		p_info->flag |= flag_dot;	
	if (*fmt == '#')
		p_info->flag |= flag_hash;
	if ((*fmt > '0' || *fmt <= '9') && !(p_info->width))
		f_i = set_width_preci(p_info, 0, fmt);
	return (f_i);
}
