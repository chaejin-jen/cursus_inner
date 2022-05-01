/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:57:34 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/28 14:35:53 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atoi_init(int *sign, int *tmp, int *sum)
{
	*sign = 1;
	*tmp = 0;
	*sum = 0;
}

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
