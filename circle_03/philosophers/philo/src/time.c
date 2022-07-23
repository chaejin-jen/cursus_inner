/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:33:55 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/23 13:33:53 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

float	time_diff(t_tv *start, t_tv *end)
{
	return (((float)(end->tv_sec - start->tv_sec)) * 1000 \
			+ ((float)(end->tv_usec - start->tv_usec)) / 1000);
}

long long	get_nticks(void)
{
	t_tv	t_val;

	gettimeofday(&t_val, NULL);
	return (t_val.tv_sec * 1000000.L + (long long)t_val.tv_usec);
}

void	msleep(long long end)
{
	while (get_nticks() < end)
		usleep (750);
}

int	limit_msleep(long long end, long long limit_end)
{
	int			is_over;

	is_over = 0;
	if (end > limit_end)
	{
		is_over = 1;
		end = limit_end;
	}
	while (get_nticks() < end)
		usleep (750);
	return (is_over);
}
