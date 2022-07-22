/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:51 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/22 13:20:06 by chaejkim         ###   ########.fr       */
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
		usleep(10);
	if (clear_table(&table, sinfo->number) != 0)
		return (1);
	return (0);
}
