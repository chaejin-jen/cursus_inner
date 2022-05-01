/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_info_apply_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:24:33 by chaejkim          #+#    #+#             */
/*   Updated: 2022/02/13 17:31:03 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_strndup(char *s, size_t n)
{
	char	*result;
	size_t	i;


	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < n)
		result[i] = s[i];
	result[i] = '\0';
	free(s);
	return (result);
}

char	*strjoin_flag(t_print_info p_info, char *s, size_t *s_len)
{
	char	c;
	char	*result;

	if (*s_len < p_info.preci)
		*s_len = p_info.preci;
	if (*s_len > p_info.width)
		return (ft_strndup(s, *s_len));
	if (p_info.flag & flag_minus)
		return (ft_strndup(s, *s_len));
	result = (char *)malloc_end_null(p_info.width, sizeof(char));
	if (!result)
		return (NULL);
	c = ' ';
	if (p_info.flag & flag_zero)
		c = '0';
	if (p_info.flag & flag_minus)
	{
		ft_memcpy(result, s, *s_len);
		ft_memset(result + *s_len, c, p_info.width - *s_len);
	}
	else
	{
		ft_memset(result, c, *s_len);
		ft_memcpy(result + *s_len, s, p_info.width - *s_len);
	}
	*s_len = p_info.width;
	result[*s_len] = '\0';
	return (result);
}

