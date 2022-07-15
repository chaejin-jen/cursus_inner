/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:33:55 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/15 16:27:39 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

float	time_diff(t_tv *start, t_tv *end)
{
	return (((float)(end->tv_sec - start->tv_sec)) * 1000 \
			+ ((float)(end->tv_usec - start->tv_usec)) / 1000);
}

long long	nticks(t_tv *t)
{
	return (((long long)(t->tv_sec)) * 1000000 + ((long long)(t->tv_usec)));
}

long long	get_nticks(void)
{
	t_tv	t_val;

	gettimeofday(&t_val, NULL);
	return (nticks(&t_val));
}

long long	get_elasped_time(long long start)
{
	return (get_nticks() - start);
}

int	limit_msleep(long long end, int limit_time)
{
	int			is_over;

	is_over = 1;
	if (end < (get_nticks() + limit_time * 1000))
		is_over = 0;
	while (get_nticks() < end)
		usleep (750);
	return (is_over);
}
