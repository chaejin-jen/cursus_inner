/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:33:12 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/02 03:40:32 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	unsigned char	u_c;

	u_c = (unsigned char)c;
	return (write(1, &u_c, 1));
}

int	print_s(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		s = "(null)";
	while (s[len])
		len++;
	return (write(1, s, len));
}
