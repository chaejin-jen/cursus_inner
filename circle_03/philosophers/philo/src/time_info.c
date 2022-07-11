/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:33:55 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 04:40:11 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(long long wait_time)
{
	usleep((int)wait_time * 1000);
}

long long	mticks()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}

static float	time_diff(struct timeval *start, struct timeval *end)
{
	if (end->tv_usec - start->tv_usec < 0)
	{
		end->tv_usec += 1000000L;
		end->tv_sec -= 1;
	}
	return ((long long)((end->tv_usec - start->tv_usec) / 1000));
}

void	init_time_info(t_time_info *tinfo)
{
	memset(tinfo->last_eat, 0, sizeof(struct timeval));
	memset(tinfo->last_act, 0, sizeof(struct timeval));
	memset(tinfo->time_to_die, 0, sizeof(float));
	memset(tinfo->time_to_act, 0, sizeof(float));
}

void	update_time_info(t_time_info *tinfo, struct timeval *current)
{
	tinfo->time_to_die = time_diff(&tinfo->last_eat, &current);
	tinfo->time_to_act += time_diff(&tinfo->last_act, &current);
	tinfo->last_act.tv_sec = current->tv_sec;
	tinfo->last_act.tv_usec = current->tv_usec;
}
