/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:51 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 03:57:10 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_tinfo(t_philo_info *philos, unsigned int	number)
{
	int			cnt;
	int			pnum;
	t_time_info	*tinfo;

	cnt = 0;
	while (cnt < 2)
	{
		pnum = cnt++ % 2 - 1;
		while (pnum < number - 1)
		{
			pnum += 2;
			tinfo = &philos[pnum].tinfo

			gettimeofday(&(tinfo->last_eat), NULL);
			tinfo->last_act.tv_sec = tinfo->last_eat.tv_sec;
			tinfo->last_act.tv_usec = tinfo->last_eat.tv_usec;
		}
		usleep(100);
	}
}

int	run_simulation(const t_simulation_info *sinfo)
{
	t_table_info	table;
	int				s;

	if (set_table(&table, sinfo) != 0)
		return (1);
	gettimeofday(&sinfo->current, NULL);
	set_tinfo(table.philos, table.sinfo->number);
	while (monitor(&table, sinfo->number) != 0)
	{
		pthread_mutex_lock(&sinfo->timer);
		gettimeofday(&sinfo->current, NULL);
		pthread_mutex_unlock(&sinfo->timer);
		usleep(100);
	}
	if (clear_table(&table,) != 0)
		return (1);
}
