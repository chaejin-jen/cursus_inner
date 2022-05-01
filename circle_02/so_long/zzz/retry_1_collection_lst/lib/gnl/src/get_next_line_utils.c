/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:52:19 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/09 16:24:22 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	index_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

//size_t	ft_strlen(const char *s)
//{
//	size_t	len;

//	len = 0;
//	while (*s++)
//		len++;
//	return (len);
//}

//void	*ft_memcpy(void *dst, const void *src, size_t n)
//{
//	unsigned char		*dst_tmp;
//	const unsigned char	*src_tmp;

//	dst_tmp = dst;
//	src_tmp = src;
//	if (dst_tmp == src_tmp)
//		return (dst);
//	while (n-- > 0)
//		*dst_tmp++ = *src_tmp++;
//	return (dst);
//}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < n)
		result[i] = s1[i];
	result[i] = '\0';
	return (result);
}

//char	*ft_strjoin(char *s1, char *s2)
//{
//	char	*result;
//	int		s1_len;
//	int		s2_len;

//	if (!s1 && !s2)
//		return (NULL);
//	if (!s1)
//		return (ft_strndup(s2, ft_strlen(s2)));
//	if (!s2)
//		return (ft_strndup(s1, ft_strlen(s1)));
//	s1_len = ft_strlen(s1);
//	s2_len = ft_strlen(s2);
//	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
//	if (!result)
//		return (NULL);
//	ft_memcpy(result, s1, s1_len);
//	ft_memcpy(result + s1_len, s2, s2_len + 1);
//	return (result);
//}
