/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:51 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/09 17:16:08 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_simulation(t_simulation_info *sinfo)
{
	t_table_info	table;

	if (set_table(&table, sinfo) != 0)
		return (1);
	pthread_mutex_lock(&sinfo->timer);
	sinfo->start = get_mticks();
	pthread_mutex_unlock(&sinfo->timer);
	while (monitor(&table) != 0)
		usleep(750);
	if (clear_table(&table, sinfo->number) != 0)
		return (1);
	return (0);
}
