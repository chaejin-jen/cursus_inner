/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:17:42 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 04:51:15 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_table_info		*table;
	t_philo_info		*philo;
	t_simulation_info	*sinfo;

	table = (t_table_info *)arg;
	philo = &table->philos[table->seat_num];
	sinfo = table->sinfo;
	while (philo->tinfo.last_eat.tv_sec == 0 && philo->tinfo.last_eat.tv_usec == 0)
		;
	while (philo->rest_eat != 0)
	{
		pthread_mutex_lock(&sinfo->timer);
		update_tinfo(&philo->tinfo, &sinfo->current);
		pthread_mutex_unlock(&sinfo->timer);
		if (philo->tinfo.time_to_die > sinfo->time_to_die)
		{
			dying(philo->philo_num, sinfo);
			break ;
		}
		start_eating(philo, philo->finfo, sinfo);
		//pthread_mutex_lock(&sinfo->timer);
		//update_tinfo(&philo->tinfo, &sinfo->current);
		//pthread_mutex_unlock(&sinfo->timer);
		end_eating(philo, philo->finfo, sinfo);
		usleep(30);
	}
	return (0);
}
