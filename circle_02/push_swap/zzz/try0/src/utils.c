/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:57:34 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/03 18:27:28 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pptr(void **pptr)
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
}

void	num_init(long *num, t_list *lst)
{
	num[0] = (long)lst->content;
	num[1] = (long)lst->next->content;
	num[2] = (long)lst->next->next->content;
}
