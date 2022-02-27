/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:53:07 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/13 14:46:15 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strchr_index(const char *s, int c)
{
	const char	*ptr;

	ptr = (const char *)s;
	while (*ptr && (*ptr != (unsigned char)c))
		ptr++;
	return ((int)(ptr - s));
}

char	*malloc_end_null(size_t count, size_t size)
{
	char	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ptr[size - 1] = '\0';
	return (ptr);
}
