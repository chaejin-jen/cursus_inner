/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:51 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 18:29:41 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_simulation(const t_simulation_info *sinfo)
{
	t_thread_info	*philos;
	t_mutex_info	*forks;
	t_time_info		tinfo;
	int				cnt;
	int				tnum;

	cnt = 0;
	if (set_table(&table, &sinfo) != 0)
		return (1);
	// philo_num = sinfo->number;
	gettimeofday(&tinfo.start, NULL);
	while (cnt < 2)
	{
		tnum = cnt++ % 2 - 1;
		while (tnum < sinfo->number - 1)
			set_philos_time(philos);
	}
	while (/* condition */)
	{
		gettimeofday(&tinfo.end, NULL);
		if (monitor() != 0)
			break ;
	}
}