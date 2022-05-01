/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:18 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/02 01:19:42 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_lst_add(t_map *map, int col, int lines_num)
{
	t_list		*new_lst;
	t_vector	*pos;

	pos = (t_vector *)malloc(sizeof(t_vector));
	if (pos == NULL)
	{
		if (map->exit_lst)
			ft_lstclear(&map->exit_lst, free);
		return (error_message("malloc failed (exit lst)\n"));
	}
	pos->x = col;
	pos->y = lines_num;
	new_lst = ft_lstnew((void *)pos);
	if (new_lst == NULL)
	{
		free(pos);
		if (map->exit_lst)
			ft_lstclear(&map->exit_lst, free);
		return (error_message("malloc failed (exit_lst)\n"));
	}
	ft_lstadd_front(&map->exit_lst, new_lst);
	return (0);
}

static int	valid_wall(t_map *map, char *buf, int cols, int lines_nums)
{
	int	i;

	if (*buf == '\0')
		return (!error_message("empty line in map\n"));
	if (cols != map->cols)
		return (!error_message("not rectangle map\n"));
	if (map->rows == 0 || lines_nums == 0)
	{
		i = 0;
		while (i < map->cols)
		{
			if (*buf != '1')
				return (!error_message("not rectangle walls (top/bottom)\n"));
			buf++;
			i++;
		}
		return (1);
	}
	if (*buf != '1' || *(buf + map->cols - 1) != '1')
		return (!error_message("not rectangle walls (left/right)\n"));
	return (1);
}

static int	valid_object_set(t_map *map, char *buf, int lines_num)
{
	int	col;

	col = -1;
	while (++col < map->cols)
	{
		if (*buf != '0' && *buf != '1' && *buf != 'C'
			&& *buf != 'E' && *buf != 'P')
			return (!error_message("unvalid charcters\
				\nnote: '0(empty)', '1(wall)',\
				\n\t'C(collection)', 'E(exit)', 'P(player)'\n"));
		if (*buf == 'C')
			map->obj_c++;
		else if (*buf == 'E')
		{
			if (exit_lst_add(map, col, lines_num) == -1)
				return (!error_message("malloc failed (exit lst)\n"));
			map->obj_e++;
		}
		else if (*buf == 'P')
		{
			if (map->obj_p)
				*buf = '0';
			map->obj_p++;
		}
		buf++;
	}
	return (1);
}

int	valid_map(t_map *map, char *buf, int cols, int lines_num)
{
	int	is_valid;

	is_valid = (valid_wall(map, buf, cols, lines_num)
			&& valid_object_set(map, buf, lines_num));
	if (lines_num == 0)
	{
		if (map->obj_e == 0)
			is_valid &= !error_message("number of exits (at least 1)\n");
		if (map->obj_p == 0)
		{
			ft_lstclear(&map->exit_lst, free);
			is_valid &= !error_message("number of players (at least 1)\n");
		}
		if (map->obj_c == 0)
		{
			ft_lstclear(&map->exit_lst, free);
			is_valid &= !error_message("number of collect (at least 1)\n");
		}
	}
	return (is_valid);
}
