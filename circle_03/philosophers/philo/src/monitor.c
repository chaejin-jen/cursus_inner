/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:22:48 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/09 16:58:49 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_end(pthread_mutex_t *monitor, t_simulation_info *sinfo)
{
	pthread_mutex_lock(monitor);
	if (sinfo->number == sinfo->end_number)
	{
		timestamp(sinfo, 0, FINISH, TRUE);
		pthread_mutex_unlock(monitor);
		return (1);
	}
	pthread_mutex_unlock(monitor);
	return (0);
}

static int	check_philos(pthread_mutex_t *timer,
		t_philo_info *philos, t_simulation_info *sinfo)
{
	int				tnum;
	int				pnum;
	long long		recent_eat;

	tnum = -1;
	pnum = -1;
	recent_eat = get_mticks();
	while (++tnum < sinfo->number)
	{
		pthread_mutex_lock(timer);
		if (philos[tnum].recent_act == 0
			|| get_mticks() > philos[tnum].recent_eat + sinfo->time_to_die)
		{
			if (philos[tnum].recent_eat < recent_eat)
			{
				recent_eat = philos[tnum].recent_eat;
				pnum = tnum;
			}
			pthread_mutex_unlock(timer);
		}
		pthread_mutex_unlock(timer);
	}
	if (pnum != -1)
		dying(&philos[pnum], sinfo);
	return (pnum);
}

int	monitor(t_table_info *table)
{
	if (table->sinfo->least_eat != -1
		&& check_end(&table->sinfo->monitor, table->sinfo))
		return (0);
	if (check_philos(&table->sinfo->timer, table->philos, table->sinfo) != -1)
		return (0);
	return (1);
}
