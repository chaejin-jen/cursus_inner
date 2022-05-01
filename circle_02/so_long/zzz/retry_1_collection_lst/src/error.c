/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:04 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/23 22:01:00 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_error(char *message)
{
	write(1, "Error\n", 6);
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	exit(-1);
}

void	malloc_error(char *message)
{
	write(1, "Error\n", 6);
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	exit(-1);
}

void	map_error(t_map *map, char *message)
{
	write(1, "Error\n", 7);
	write(1, "\033[0;31m", 8);
	write(1, message, ft_strlen(message));
	write(1, "\033[0m", 5);
	ft_lstclear(&map->tmp_lst, del_ptr);
	ft_lstclear(&map->exit_lst, free);
	ft_lstclear(&map->collect_lst, free);
	free(map);
	exit(-1);
}
