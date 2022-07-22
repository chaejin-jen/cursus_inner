/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:23:45 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/22 15:21:59 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(pthread_mutex_t *timer, t_simulation_info *sinfo)
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
}

void	sync_philos(t_simulation_info *sinfo, t_philo_info *philo)
{
	if (philo->philo_num % 2)
	{
		if (sinfo->time_to_die <= sinfo->time_to_eat)
		{
			msleep(philo->start + sinfo->time_to_die);
			dying(philo->philo_num, sinfo);
		}
		usleep(50);
	}
}

int	check_end(t_simulation_info *sinfo, t_philo_info *philo)
{
	if (sinfo->need_end == TRUE)
		return (1);
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
