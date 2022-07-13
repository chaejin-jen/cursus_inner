/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:17:42 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/13 12:59:50 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
	t_table_info *table;
	t_philo_info *philo;
	t_simulation_info *sinfo;

	table = (t_table_info *)arg;
	philo = &(table->philos[table->seat_num]);
	sinfo = table->sinfo;
	if (philo->philo_num % 2)
		usleep(50);
	usleep(100);
	// pthread_mutex_lock(&sinfo->timer);
	// while (sinfo->current.tv_sec == 0 && sinfo->current.tv_usec == 0)
	//{
	//	pthread_mutex_unlock(&sinfo->timer);
	//	usleep(50);
	// }
	// pthread_mutex_unlock(&sinfo->timer);
	set_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
	while (philo->rest_eat != 0)
	{
		if (philo->tinfo.elasped_time > sinfo->time_to_die)
		{
			dying(philo->philo_num, sinfo);
			break;
		}
		start_eating(philo, philo->finfo, sinfo);
		end_eating(philo, philo->finfo, sinfo);
		usleep(30);
	}
	pthread_mutex_lock(&sinfo->monitor);
	sinfo->number--;
	pthread_mutex_unlock(&sinfo->monitor);
	return (0);
}
