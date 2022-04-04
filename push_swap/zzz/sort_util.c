/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:17:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/05 00:48:33 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	max_in_three(long n[3])
{
	if (n[0] > n[1] && n[0] > n[2])
		return (n[0]);
	else if (n[1] > n[0] && n[1] > n[2])
		return (n[1]);
	else if (n[2] > n[0] && n[2] > n[1])
		return (n[2]);
}

long	min_in_three(long n[3])
{
	if (n[0] < n[1] && n[0] < n[2])
		return (n[0]);
	else if (n[1] < n[0] && n[1] < n[2])
		return (n[1]);
	else if (n[2] < n[0] && n[2] < n[1])
		return (n[2]);
}
