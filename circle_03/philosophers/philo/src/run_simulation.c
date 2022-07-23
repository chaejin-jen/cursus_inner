/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:51 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/23 17:19:02 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_simulation(t_simulation_info *sinfo)
{
	t_table_info	table;

	if (set_table(&table, sinfo) != 0)
		return (1);
	pthread_mutex_lock(&sinfo->timer);
	gettimeofday(&sinfo->start, NULL);
	pthread_mutex_unlock(&sinfo->timer);
	while (monitor(sinfo) != 0)
		usleep(50);
	if (clear_table(&table, sinfo->number) != 0)
		return (1);
	return (0);
}
