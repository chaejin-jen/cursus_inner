/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:17:42 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/23 16:18:06 by chaejkim         ###   ########.fr       */
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
	wait_philos(&sinfo->timer, sinfo);
	philo->start = get_nticks();
	sync_philos(sinfo, philo);
	while (philo->rest_eat != 0 && check_end(&sinfo->monitor, sinfo) == 0)
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
