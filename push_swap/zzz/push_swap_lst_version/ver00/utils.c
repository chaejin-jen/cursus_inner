/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:16:47 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/25 03:14:32 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*put_1st_2nd_last(void *first, void *second, void *last)
{
	long	result[3];

	result[0] = (long)first;
	result[1] = (long)second;
	result[2] = (long)last;
	return	(result);
}
