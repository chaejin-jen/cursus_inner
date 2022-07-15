/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:17:42 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/15 14:08:48 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_table_info		*table;
	t_philo_info		*philo;
	t_simulation_info	*sinfo;

	table = (t_table_info *)arg;
	philo = &(table->philos[table->seat_num]);
	sinfo = table->sinfo;
	wait_philos(&sinfo->timer, sinfo, philo);
	philo->last_eat = get_nticks();
	while (check_end(&sinfo->monitor, sinfo, philo) == 0)
	{
		if (take_fork(philo, philo->finfo, sinfo)
			|| eat(philo, philo->finfo, sinfo)
			|| put_down_fork(philo->finfo)
			|| psleep(philo, sinfo))
		{
			dying(philo->philo_num, sinfo);
			break ;
		}
	}
	if (philo->rest_eat != -1)
		note_end(&sinfo->monitor, sinfo);
	return (0);
}
