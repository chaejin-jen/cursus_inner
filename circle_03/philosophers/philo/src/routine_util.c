/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:23:45 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/15 13:27:12 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(pthread_mutex_t *timer,
		t_simulation_info *sinfo, t_philo_info *philo)
{
	while (1)
	{
		pthread_mutex_lock(timer);
		if (sinfo->start.tv_sec != 0 || sinfo->start.tv_usec != 0)
		{
			pthread_mutex_unlock(timer);
			break ;
		}
		pthread_mutex_unlock(timer);
	}
	if (philo->philo_num % 2)
		usleep(50);
}

int	check_end(pthread_mutex_t *monitor,
			t_simulation_info *sinfo, t_philo_info *philo)
{
	pthread_mutex_lock(monitor);
	if (sinfo->need_end == TRUE)
	{
		pthread_mutex_unlock(monitor);
		return (1);
	}
	pthread_mutex_unlock(monitor);
	if (philo->rest_eat == 0)
		return (1);
	return (0);
}

void	note_end(pthread_mutex_t *monitor, t_simulation_info *sinfo)
{
	pthread_mutex_lock(monitor);
	sinfo->number--;
	pthread_mutex_unlock(monitor);
}
