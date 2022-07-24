/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:33:55 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/24 20:29:02 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// double	time_diff(t_tv *start, t_tv *end)
// {
// 	if ((end->tv_usec - start->tv_usec) < 0)
// 	{
// 		end->tv_usec += 1000000;
// 		end->tv_sec -= 1;
// 	}
// 	return ((end->tv_sec - start->tv_sec) * 1000.0
// 		+ (end->tv_usec - start->tv_usec) / 1000.0);
// }

long long	get_mticks(void)
{
	t_tv	t_val;

	gettimeofday(&t_val, NULL);
	return (t_val.tv_sec * 1000000LL + (long long)t_val.tv_usec);
}

void	sleep_until(long long end)
{
	while (get_mticks() < end)
		usleep (750);
}

int	sleep_until_limit(long long end, long long limit_end)
{
	int			is_limit;

	is_limit = 0;
	if (end >= limit_end)
	{
		is_limit = 1;
		end = limit_end;
	}
	while (get_mticks() < end)
		usleep (750);
	return (is_limit);
}
