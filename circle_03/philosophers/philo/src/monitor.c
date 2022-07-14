/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:22:48 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/14 20:06:03 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor(t_simulation_info *sinfo)
{
	static int	philo_done = 0;

	pthread_mutex_lock(&sinfo->monitor);
	if (philo_done == sinfo->number)
	{
		pthread_mutex_unlock(&sinfo->monitor);
		return (0);
	}
	if (sinfo->need_end == TRUE)
	{
		pthread_mutex_unlock(&sinfo->monitor);
		return (0);
	}
	pthread_mutex_unlock(&sinfo->monitor);
	return (1);
}
