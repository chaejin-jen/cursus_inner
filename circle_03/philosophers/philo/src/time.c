/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:33:55 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 15:59:46 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

float	time_diff(struct timeval *start, struct timeval *end)
{
	if (end->tv_usec - start->tv_usec < 0)
	{
		end->tv_usec += 1000000L;
		end->tv_sec -= 1;
	}
	return ((end->tv_usec - start->tv_usec) / 1000);
}

void	set_philos_time(t_thread_info *philos)
{
	while (++tnum < sinfo->number)
	{
		philo = (*philos)[tnum];
		philo.thread_num = tnum + 1;
		philo.rest_eat = sinfo->least_eat;
		philo.thread_status = THINK;
		if (tnum + 1 != sinfo->number)
			philo.r_thread = &(*philos)[tnum + 1];
		else
			philo.r_thread = &(*philos)[0];
		s = pthread_create(&philo.thread_id, NULL,
				&philo_routine, &philo);
		if (s != 0)
			return (error_message("pthread_create"));
		// pthread_detach(&philo.thread_id);
	}
}

void	init_time_info(t_time_info *tinfo)
{
	gettimeofday(&tinfo->start, NULL);
	gettimeofday(&tinfo->cur, NULL);
}

void	update_run_time(t_time_info *tinfo)
{
	tinfo->run_time = time_diff(&tinfo->start, &tinfo->end);
}

void	update_execute_time(t_time_info *tinfo)
{
	tinfo->execute_time = time_diff(&tinfo->cur, &tinfo->end);
}