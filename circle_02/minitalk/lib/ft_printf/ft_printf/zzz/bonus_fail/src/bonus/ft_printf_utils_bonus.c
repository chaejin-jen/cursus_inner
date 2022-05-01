/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:53:07 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/18 16:04:14 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//char	*ft_strchr(const char *s, int c)
//{
//	while (*s != (unsigned char)c)
//	{
//		if (*s == '\0')
//			return (0);
//		s++;
//	}
//	return ((char *)s);
//}

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
