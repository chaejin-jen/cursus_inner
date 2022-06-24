/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:33:12 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/06 15:42:19 by chaejkim         ###   ########.fr       */
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
	write(1, s, len);
	return (len);
}
