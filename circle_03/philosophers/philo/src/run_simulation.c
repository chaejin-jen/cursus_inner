/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:51 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/14 22:12:35 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_simulation(t_simulation_info *sinfo)
{
	t_table_info	table;

	if (set_table(&table, sinfo) != 0)
		return (1);
	get_timer_time(&sinfo->timer, &sinfo->start);
	while (monitor(sinfo) != 0)
	{
		get_timer_time(&sinfo->timer, &sinfo->current);
		usleep(100);
	}
	if (clear_table(&table, sinfo->number) != 0)
		return (1);
	return (0);
}
