/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:39:58 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/01 21:23:01 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_pptr(void ***pptr)
{
	int	i;

	i = 0;
	while ((*pptr)[i])
	{
		free((*pptr)[i]);
		(*pptr)[i] = 0;
		i++;
	}
	free(*pptr);
	*pptr = 0;
}
