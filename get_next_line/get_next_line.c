/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:51:46 by chaejkim          #+#    #+#             */
/*   Updated: 2022/01/26 18:08:19 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	split_prestr(char **result, char *prestr)
{
	int	i;
	int	nl_i;

	if (*prestr == '\0')
	{
		*result = NULL;
		return (0);
	}
	i = 0;
	nl_i = index_nl(prestr);
	if (nl_i == -1)
		*result = ft_strndup(prestr, BUFFER_SIZE);
	else
	{
		*result = ft_strndup(prestr, nl_i + 1);
		while (++nl_i < BUFFER_SIZE + 1)
			prestr[i++] = prestr[nl_i];
		return (1);
	}
	prestr[i] = '\0';
	return (0);
}

static void	join_buf(char *buf, char **result, char *prestr, int size)
{
	int		i;
	char	*tmp;
	char	*join_str;

	i = 0;
	tmp = *result;
	if (size == -1)
	{
		*result = ft_strjoin(*result, buf);
		free(tmp);
	}
	else
	{
		join_str = ft_strndup(buf, size + 1);
		*result = ft_strjoin(*result, join_str);
		while (++size < BUFFER_SIZE)
			prestr[i++] = buf[size];
		free(join_str);
		free(tmp);
	}
	while (i < BUFFER_SIZE)
		prestr[i++] = '\0';
}

static int	read_check(int fd, char *buf)
{
	int	len;

	len = read(fd, buf, BUFFER_SIZE);
	buf[len] = '\0';
	return (len);
}

char	*get_next_line(int fd)
{
	static char	prestr[BUFFER_SIZE + 1];
	char		*result;
	char		buf[BUFFER_SIZE + 1];
	int			check;
	int			nl_i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (split_prestr(&result, prestr))
		return (result);
	while (42)
	{
		check = read_check(fd, buf);
		if (check == -1)
		{
			free(result);
			return (NULL);
		}
		if (check == 0)
			return (result);
		nl_i = index_nl(buf);
		join_buf(buf, &result, prestr, nl_i);
		if (nl_i != -1)
			return (result);
	}
}
