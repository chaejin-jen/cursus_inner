/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:57:52 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/15 16:07:52 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->rows = 0;
	map->cols = 0;
	map->obj_c = 0;
	map->obj_e = 0;
	map->obj_p = 0;
	map->player.pos.x = 0;
	map->player.pos.y = 0;
	map->exit_lst = 0;
	map->collect_lst = 0;
	map->tmp_lst = 0;
	return (map);
}
