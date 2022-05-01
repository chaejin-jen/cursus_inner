/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:04 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/02 01:47:55 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_message(char *message)
{
	write(1, "Error\n", 6);
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	return (-1);
}

void	error_exit(char *message)
{
	error_message(message);
	exit(1);
}

void	read_error_exit(t_list **buf_lst, char *line, char *message)
{
	error_message(message);
	ft_lstclear(buf_lst, 0);
	free(line);
	exit(1);
}

void	map_error_exit(t_map *map, t_list *buf_lst)
{
	free(map->data);
	free(map);
	ft_lstclear(&buf_lst, free);
	exit(1);
}
