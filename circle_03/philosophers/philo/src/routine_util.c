/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:23:45 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/25 19:18:41 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(t_table_info *table,
			t_philo_info **philo, t_simulation_info **sinfo)
{
	pthread_mutex_t	*timer;
	long long		*start;

	pthread_mutex_lock(&table->sinfo->monitor);
	*philo = &(table->philos[table->seat_num]);
	*sinfo = table->sinfo;
	pthread_mutex_unlock(&table->sinfo->monitor);
	timer = &table->sinfo->timer;
	start = &(*sinfo)->start;
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
	philo->recent_eat = get_mticks();
	philo->recent_act = philo->recent_eat;
	if (philo->pnum % 2)
	{
		if (sinfo->time_to_die <= sinfo->time_to_eat)
		{
			sleep_until(philo->recent_eat + sinfo->time_to_die);
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
