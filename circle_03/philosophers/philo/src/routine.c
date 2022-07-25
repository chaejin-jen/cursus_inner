/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:17:42 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/25 18:36:39 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo_info		*philo;
	t_simulation_info	*sinfo;

	wait_philos((t_table_info *)arg, &philo, &sinfo);
	sync_philos(sinfo, philo);
	while (philo->rest_eat != 0 && philo->recent_act != 0)
	{
		if (take_fork(philo, philo->finfo, sinfo)
			|| eat(philo, philo->finfo, sinfo)
			|| put_down_fork(philo->finfo)
			|| psleep(philo, sinfo))
		{
			dying(philo, sinfo);
			break ;
		}
	}
	if (philo->rest_eat != -1)
		note_end(&sinfo->monitor, sinfo);
	return (0);
}
