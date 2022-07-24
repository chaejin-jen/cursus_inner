/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:23:45 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/24 21:21:50 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(pthread_mutex_t *timer, t_simulation_info *sinfo)
{
	pthread_mutex_lock(&sinfo->monitor);
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
	pthread_mutex_unlock(&sinfo->monitor);
}

void	sync_philos(t_simulation_info *sinfo, t_philo_info *philo)
{
	philo->start = get_mticks();
	philo->recent_eat = philo->start;
	philo->recent_act = philo->start;
	if (philo->pnum % 2)
	{
		if (sinfo->time_to_die <= sinfo->time_to_eat)
		{
			sleep_until(philo->start + sinfo->time_to_die);
			dying(philo, sinfo);
		}
		usleep(50);
	}
}

void	note_end(pthread_mutex_t *monitor, t_simulation_info *sinfo)
{
	pthread_mutex_lock(monitor);
	sinfo->end_number++;
	pthread_mutex_unlock(monitor);
}
