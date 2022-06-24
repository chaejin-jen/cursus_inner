/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntnbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:42:15 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/06 16:39:36 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	count_len(unsigned int u_i, unsigned int base)
{
	size_t	len;

	len = 1;
	while (u_i > base - 1)
	{
		len++;
		u_i /= base;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int u_i, size_t len, unsigned int base, char *digits)
{
	char	*str;
	
	str = (char *)malloc_end_null(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (u_i > base - 1)
	{
		str[--len] = digits[u_i % base];
		u_i /= base;
	}
	str[--len] = digits[u_i % base];
	return (str);
}

int	print_d(t_print_info p_info, int n)
{
	char	*result;
	int		minus;
	size_t	len;
	long	long_n;

	p_info.type = 'd';
	long_n = (long)n;
	minus = 0;
	if (long_n < 0)
	{
		minus = 1;
		long_n *= -1;
	}
	len = count_len((unsigned int)long_n, 10) + minus;
	result = ft_uitoa((unsigned int)long_n, len, 10, "0123456789");
	if (minus)
		result[0] = '-';
	write(1, result, len);
	free(result);
	return (len);
}

int	print_u(t_print_info p_info, unsigned int u_i)
{
	char	*result;
	size_t	len;

	if (p_info.type == 'u')
	{
		len = count_len(u_i, 10);
		result = ft_uitoa(u_i, len, 10, "0123456789");
	}
	if (p_info.type == 'x')
	{
		len = count_len(u_i, 16);
		result = ft_uitoa(u_i, len, 16, "0123456789abcdef");
	}
	if (p_info.type == 'X')
	{
		len = count_len(u_i, 16);
		result = ft_uitoa(u_i, len, 16, "0123456789ABCDEF");
	}
	write(1, result, len);
	free(result);
	return (len);
}
