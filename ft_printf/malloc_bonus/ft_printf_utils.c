/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:53:07 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/06 13:01:00 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

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

/*
char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strndup(s2, size));
	if (!s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	s1_len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (s1_len + size + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, size);
	result[s1_len + size] = '\0';
	return (result);
}
*/
