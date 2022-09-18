/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:33:55 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/09 18:55:38 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_mticks(void)
{
	t_tv	t_val;

	gettimeofday(&t_val, NULL);
	return (t_val.tv_sec * 1000LL + (long long)t_val.tv_usec / 1000);
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
	if (end > limit_end)
	{
		is_limit = 1;
		end = limit_end + 1;
	}
	while (get_mticks() < end)
		usleep (750);
	return (is_limit);
}
