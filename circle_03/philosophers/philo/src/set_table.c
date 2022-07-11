/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:53:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 04:25:00 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_fork(t_fork_info **forks, int n_fork)
{
	t_fork_info	finfo;
	int			fnum;
	int			s;

	*forks = (t_fork_info *)malloc(n_fork * sizeof(t_fork_info) + 1);
	if (*forks == NULL)
		return (error_message("malloc (forks)"));
	fnum = -1;
	while (++fnum < n_fork)
	{
		finfo = (*forks)[fnum];
		finfo.thread_num = 0;
		s = pthread_mutex_init(&finfo.mutex_id, NULL);
		if (s != 0)
			return (error_message("pthread_mutex_init (fork)"));
	}
	(*forks)[fnum] = (*forks)[0];
	return (0);
}

static int	set_philo(t_table_info *table, t_philo_info **philos, int n_philo)
{
	int				s;
	int				pnum;
	t_philo_info	pinfo;

	*philos = (t_philo_info *) malloc(n_philo * sizeof(t_philo_info));
	if (*philos == NULL)
		return (error_message("malloc (philos)"));
	pnum = -1;
	while (++pnum < n_philo)
	{
		pinfo = (*philos)[pnum];
		table->seat_num = pnum + 1;
		pinfo.philo_num = pnum + 1;
		pinfo.state = THINK;
		pinfo.rest_eat = table->sinfo->least_eat;
		pinfo.finfo = &table->forks[pnum];
		init_time_info(&pinfo.tinfo);
		s = pthread_create(&pinfo.thread_id, NULL, &routine, table);
		if (s != 0)
			return (error_message("pthread_create"));
		usleep(10);
		pthread_detach(&pinfo.thread_id);
	}
	return (0);
}

//int init_mutex()

int	set_table(t_table_info *table, const t_simulation_info *sinfo)
{
	//if (init_mutex(&table, sinfo) != 0)
	//	return (1);
	table->sinfo = sinfo;
	if (set_fork(table->forks, sinfo->number) == -1)
		return (1);
	if (set_philo(table, &table->philos, sinfo->number) == -1)
		return (1);
	return (0);
}
