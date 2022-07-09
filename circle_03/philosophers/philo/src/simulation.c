/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:51 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/09 18:17:10 by chaejkim         ###   ########.fr       */
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

int	start_eating(t_thread_info *tinfo)
{
	pthread_mutex_lock(tinfo->thread_id);
	tinfo->thread_status = EATING;
	printf("timestamp_in_ms %d has taken a fork", tinfo->thread_num);
	printf("timestamp_in_ms %d is eating", tinfo->thread_num);
}

int	end_eating(t_thread_info *tinfo)
{
	pthread_mutex_unlock(tinfo->thread_id);
	tinfo->thread_status = THINK;
	printf("timestamp_in_ms %d is thinking", tinfo->thread_num);
}

int	simulation(t_philo_info *pinfo, t_thread_info *tinfo, t_mutex_info *minfo)
{
	struct timeval	start;
	struct timeval	cur;
	struct timeval	end;
	int				cnt;
	unsigned int	philo_num;

	cnt = 0;
	gettimeofday(&start, NULL);
	while (1)
	{
		philo_num = cnt++ % 2 - 1;
		while (philo_num < pinfo->number_of_philo)
		{
			
			if (tinfo[philo_num].thread_status != EATING
				&& tinfo[philo_num + 1].least_eat != 0)
				start_sleep(&tinfo[philo_num]);
			philo_num += 2;
			if (tinfo[philo_num].thread_status == THINK
				&& tinfo[philo_num].least_eat != 0)
				start_eating(&tinfo[philo_num]);
		}
		
		gettimeofday(&end, NULL);
		if (monitor() != 0 || pinfo->number_of_philo == 0)
			break ;
		usleep(10);
	}
}