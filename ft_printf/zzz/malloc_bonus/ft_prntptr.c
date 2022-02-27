/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:31:33 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/06 13:25:17 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_len(size_t u_i)
{
	size_t	len;

	len = 1;
	while (u_i > 15)
	{
		len++;
		u_i /= 16;
	}
	return (len);
}

static char	*hex_addr(size_t addr, int len)
{
	char	*str;
	
	str = (char *)malloc_end_null(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	while (addr > 15)
	{
		str[--len] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	str[--len] = "0123456789abcdef"[addr % 16];
	return (str);
}

int	print_p(t_print_info p_info, void *addr)
{
	int		len;
	char	*result;

	p_info.type = 'p';
	len = count_len((size_t)addr) + 2;
	result = hex_addr((size_t)addr, len);
	write(1, result, len);
	free(result);
	return (len);
}
