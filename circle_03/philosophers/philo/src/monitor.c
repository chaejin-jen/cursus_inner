/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:22:48 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/25 21:04:40 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_end(pthread_mutex_t *monitor, t_simulation_info *sinfo)
{
	pthread_mutex_lock(monitor);
	if (sinfo->number == sinfo->end_number)
	{
		pthread_mutex_unlock(monitor);
		return (0);
	}
	pthread_mutex_unlock(monitor);
	return (1);
}

static int	check_philos(pthread_mutex_t *timer,
		t_philo_info *philos, t_simulation_info *sinfo)
{
	int				tnum;

	tnum = -1;
	while (++tnum < sinfo->number)
	{
		pthread_mutex_lock(timer);
		if (philos[tnum].recent_act == 0
			|| get_mticks() > philos[tnum].recent_eat + sinfo->time_to_die)
		{
			dying(&philos[tnum], sinfo);
			pthread_mutex_unlock(timer);
			return (0);
		}
		pthread_mutex_unlock(timer);
	}
	return (1);
}

int	monitor(t_table_info *table)
{
	static int	i = 0;

	if (table->sinfo->least_eat != -1
		&& check_end(&table->sinfo->monitor, table->sinfo))
		return (0);
	if (check_philos(&table->sinfo->timer, table->philos, table->sinfo))
		return (0);
	i++;
	if (i % 10 == 0)
		i++;
	return (1);
}
