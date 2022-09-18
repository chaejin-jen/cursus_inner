/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:23:45 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/20 17:32:55 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(pthread_mutex_t *timer, long long *start)
{
	while (1)
	{
		pthread_mutex_lock(timer);
		if (*start)
		{
			pthread_mutex_unlock(timer);
			break ;
		}
		pthread_mutex_unlock(timer);
	}
}

void	sync_philos(t_simulation_info *sinfo, t_philo_info *philo)
{
	pthread_mutex_lock(&sinfo->timer);
	philo->recent_eat = get_mticks();
	philo->recent_act = philo->recent_eat;
	pthread_mutex_unlock(&sinfo->timer);
	if (philo->pnum % 2)
	{
		if (sinfo->time_to_die <= sinfo->time_to_eat)
			sleep_until(philo->recent_eat + sinfo->time_to_die);
		usleep(750);
	}
}

void	note_end(pthread_mutex_t *monitor, t_simulation_info *sinfo)
{
	pthread_mutex_lock(monitor);
	sinfo->end_number++;
	if (sinfo->number == sinfo->end_number)
		timestamp(sinfo, 0, FINISH, TRUE);
	pthread_mutex_unlock(monitor);
}
