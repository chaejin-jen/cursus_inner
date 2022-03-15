/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:51:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/15 16:30:44 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_lst_add(t_map *map, void *content)
{
	t_list	*new_lst;

	new_lst = ft_lstnew(content);
	if (!new_lst)
		read_error("malloc failed\n");
	if (!map->tmp_lst)
		map->tmp_lst = new_lst;
	else
		ft_lstadd_front(&map->tmp_lst, new_lst);
}

t_vector	vector_init(int x, int y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	calc_vector(t_vector dst_pos, t_vector cur_pos)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	if (dst_pos.x < cur_pos.x)
		pos.x = -1;
	else if (dst_pos.x > cur_pos.x)
		pos.x = 1;
	if (dst_pos.y < cur_pos.y)
		pos.y = -1;
	else if (dst_pos.y > cur_pos.y)
		pos.y = 1;
	return (pos);
}

void	del_ptr(void *ptr)
{
	ptr = 0;
}

void	free_pptr(char **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
	{
		free(pptr[i]);
		pptr[i] = 0;
		i++;
	}
	free(pptr);
	pptr = 0;
	return ;
}
