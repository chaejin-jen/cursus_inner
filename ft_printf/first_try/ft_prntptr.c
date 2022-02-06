/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:31:33 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/02 03:42:27 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_hex_addr(size_t addr, int *write_byte)
{
	if (addr < 1)
	{
		*write_byte += write(1, "0x", 2);
		return ;
	}
	write_hex_addr(addr / 16, write_byte);
	*write_byte += write(1, &"0123456789abcdef"[addr % 16], 1);
}

int	print_p(void *addr)
{
	int	write_byte;

	write_byte = 0;
	if (addr == NULL)
		return (write(1, "0x0", 3));
	write_hex_addr((size_t)addr, &write_byte);
	return (write_byte);
}
