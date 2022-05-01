/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:35 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/18 17:03:35 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_strtol(const char *str)
{
	int	sign;
	int	tmp;
	int	sum;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	sum = 0;
	tmp = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = (sum * 10) + sign * (*str - '0');
		if (sum > 0 && tmp < 0)
			print_error();
		if (sum < 0 && tmp > 0)
			print_error();
		sum = tmp;
		str++;
	}
	if (sum == 0)
		print_error();
	return (sum);
}

int	ft_swap_atoi(const char *str)
{
	return ((int)ft_strtoint(str));
}
