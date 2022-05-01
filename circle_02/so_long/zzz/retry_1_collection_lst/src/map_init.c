/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:57:52 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/23 22:48:17 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_vector	**pos_init(t_map *map)
{
	t_vector	**pos;
	t_vector	*pos1;
	t_vector	*pos2;

	pos = (t_vector **)malloc(sizeof(t_vector *) * 2);
	pos1 = (t_vector *)malloc(sizeof(t_vector));
	if (pos1 == NULL)
	{
		free(map);
		free(map->tmp_lst);
		malloc_error("malloc_failed (pos_init)");
	}
	pos2 = (t_vector *)malloc(sizeof(t_vector));
	if (pos2 == NULL)
	{
		free(map);
		free(pos1);
		free(map->tmp_lst);
		malloc_error("malloc_failed (pos_init)");
	}
	*pos1 = vector_init(0, 0);
	*pos2 = vector_init(0, 0);
	pos[0] = pos1;
	pos[1] = pos2;
	return (pos);
}

static void	init_error_one(t_map *map, t_vector **pos)
{
	free(map);
	free(map->tmp_lst);
	free(pos[0]);
	free(pos[1]);
	free(pos);
	malloc_error("malloc failed (collect_lst)");
}

static void	init_error_two(t_map *map, t_vector **pos)
{
	free(map);
	free(map->tmp_lst);
	free(map->collect_lst);
	free(pos[0]);
	free(pos[1]);
	free(pos);
	malloc_error("malloc failed (exit_lst)");
}

static void	map_lst_init(t_map *map)
{
	t_vector	**pos;

	map->tmp_lst = ft_lstnew((void *) -1);
	if (map->tmp_lst == NULL)
	{
		free(map);
		malloc_error("malloc failed (tmp_lst)");
	}
	pos = pos_init(map);
	map->collect_lst = ft_lstnew((void *)pos[0]);
	if (map->collect_lst == NULL)
		init_error_one(map, pos);
	map->exit_lst = ft_lstnew((void *)pos[1]);
	if (map->exit_lst == NULL)
		init_error_two(map, pos);
	free(pos);
}

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		malloc_error("malloc_failed (map)");
	map->rows = 0;
	map->cols = 0;
	map->obj_c = 0;
	map->obj_e = 0;
	map->obj_p = 0;
	map->player.pos.x = 0;
	map->player.pos.y = 0;
	map_lst_init(map);
	return (map);
}
