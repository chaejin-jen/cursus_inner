/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:22:48 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/12 17:07:38 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philos(pthread_mutex_t *timer,
		t_philo_info *philos, t_simulation_info *sinfo)
{
	int				tnum;
	static int		pnum = -1;
	long long		recent_eat;

	tnum = -1;
	recent_eat = get_mticks();
	while (++tnum < sinfo->number)
	{
		if (pnum == -1)
			pthread_mutex_lock(timer);
		if (get_mticks() > philos[tnum].recent_eat + sinfo->time_to_die
			&& philos[tnum].recent_eat < recent_eat)
		{
			recent_eat = philos[tnum].recent_eat;
			pnum = tnum;
		}
		if (pnum == -1)
			pthread_mutex_unlock(timer);
	}
	if (pnum != -1)
	{
		timestamp(sinfo, pnum + 1, DEAD, TRUE);
		pthread_mutex_unlock(timer);
	}
	return (pnum);
}

int	monitor(t_table_info *table)
{
	if (check_philos(&table->sinfo->timer, table->philos, table->sinfo) != -1)
		return (0);
	return (1);
}
