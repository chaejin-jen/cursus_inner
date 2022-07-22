/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:22:48 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/22 15:01:23 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor(t_simulation_info *sinfo)
{
	pthread_mutex_lock(&sinfo->monitor);
	if (sinfo->number == 0)
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
