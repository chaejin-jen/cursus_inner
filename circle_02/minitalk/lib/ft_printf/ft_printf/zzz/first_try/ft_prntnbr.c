/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:42:15 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/02 03:39:49 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_nb(unsigned int nb, size_t base, char *digits, int *write_byte)
{
	unsigned char	c;

	if (nb == 0)
	{
		*write_byte += write(1, "0", 1);
		return ;
	}
	if (nb > base - 1)
		write_nb(nb / base, base, digits, write_byte);
	c = digits[nb % base];
	*write_byte += write(1, &c, 1);
}

int	print_d(int n)
{
	long	long_n;
	int		write_byte;

	long_n = (long)n;
	write_byte = 0;
	if (long_n < 0)
	{
		write_byte += write(1, "-", 1);
		long_n = -long_n;
	}
	write_nb((unsigned int)long_n, 10, "0123456789", &write_byte);
	return (write_byte);
}

int	print_u(unsigned int u_n)
{
	int	write_byte;

	write_byte = 0;
	write_nb(u_n, 10, "0123456789", &write_byte);
	return (write_byte);
}

int	print_x_lower(unsigned int u_n)
{
	int	write_byte;

	write_byte = 0;
	write_nb(u_n, 16, "0123456789abcdef", &write_byte);
	return (write_byte);
}

int	print_x_upper(unsigned int u_n)
{
	int	write_byte;

	write_byte = 0;
	write_nb(u_n, 16, "0123456789ABCDEF", &write_byte);
	return (write_byte);
}
