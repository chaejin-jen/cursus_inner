/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntchar_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:33:12 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/13 17:20:38 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_c(t_print_info p_info, int c)
{
	size_t	len;
	char	*result;

	len = 1;
	if (p_info.width || p_info.preci)
	{
		strjoin_flag(p_info, (char *)&c, &len);
		return (write(1, result, len));
	}
	return (write(1, &c, 1));
}

int	print_s(t_print_info p_info, char *s)
{
	size_t	len;
	char	*result;

	p_info.type = 's';
	len = 0;
	if (s == NULL)
		s = "(null)";
	while (s[len])
		len++;
	if (len > p_info.preci)
		s[p_info.preci] = '\0';
	if (p_info.flag)
		result = strjoin_flag(p_info, s, &len);
	write(1, result, len);
	return (len);
}
