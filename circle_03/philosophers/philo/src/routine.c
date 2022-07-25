/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:17:42 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/25 21:28:44 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo_info		*philo;
	t_simulation_info	*sinfo;

	philo = (t_philo_info *)arg;
	sinfo = philo->sinfo;
	wait_philos(&sinfo->timer, &sinfo->start);
	sync_philos(sinfo, philo);
	while (philo->rest_eat != 0 && philo->recent_act != 0)
	{
		if (take_fork(philo, philo->finfo, sinfo)
			|| eat(philo, philo->finfo, sinfo)
			|| put_down_fork(philo->finfo)
			|| psleep(philo, sinfo))
		{
			// dying(philo, sinfo);
			philo->recent_act = 0;
			break ;
		}
	}
	if (philo->rest_eat != -1)
		note_end(&sinfo->monitor, sinfo);
	return (0);
}
