/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:51:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/30 22:56:47 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	del_new_line(t_list **buf_lst, int *line_num)
{
	t_list	*tmp_lst;

	while (((char *)(*buf_lst)->content)[0] == '\n')
	{
		tmp_lst = *buf_lst;
		*buf_lst = (*buf_lst)->next;
		ft_lstdelone(tmp_lst, free);
		(*line_num)--;
	}
}
