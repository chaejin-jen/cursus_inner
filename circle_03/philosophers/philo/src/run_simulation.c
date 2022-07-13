/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:51 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/13 12:20:33 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int run_simulation(t_simulation_info *sinfo)
{
	// t_table_info	table;
	t_table_info *table;

	table = (t_table_info *)malloc(sizeof(t_table_info));
	if (table == NULL)
		return (error_message("malloc (table)"));
	if (set_table(table, sinfo) != 0)
		return (1);
	get_timer_time(&sinfo->timer, &sinfo->start);
	get_timer_time(&sinfo->timer, &sinfo->current);
	while (monitor(sinfo) != 0)
	{
		get_timer_time(&sinfo->timer, &sinfo->current);
		usleep(100);
	}
	if (clear_table(table, sinfo->number) != 0)
		return (1);
	return (0);
}
