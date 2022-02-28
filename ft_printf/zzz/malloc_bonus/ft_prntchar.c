/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:33:12 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/04 21:45:58 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_print_info p_info, int c)
{
	//unsigned char	*str;
	unsigned char	u_c;

	p_info.type = 'c';
	u_c = (unsigned char)c;
	return (write(1, &u_c, 1));  
}

int	print_s(t_print_info p_info, char *s)
{
	size_t	len;

	p_info.type = 's';
	len = 0;
	if (s == NULL)
		s = "(null)";
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}
