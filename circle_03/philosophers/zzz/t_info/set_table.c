/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:53:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 19:41:49 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_philo(t_table_info *table, t_simulation_info *sinfo)
{
	int				s;
	int				tnum;
	t_thread_info	philo;

	tnum = -1;
	while (++tnum < sinfo->number)
	{
		philo = (table->philos)[tnum];
		table->philo_num = tnum + 1;
		philo.thread_num = tnum + 1;
		memset(&philo.last_eat_time, 0, sizeof(struct timeval));
		s = pthread_create(&philo.thread_id, NULL, &philo_action, table);
		if (s != 0)
			return (error_message("pthread_create"));
		pthread_detach(&philo.thread_id);
	}
	(*philos)[tnum] = (*philos)[0];
	return (0);
}

static int	set_fork(t_mutex_info **forks, int num_mutex)
{
	t_mutex_info	forks_num;
	int				mnum;
	int				s;

	mnum = -1;
	while (++mnum < num_mutex)
	{
		forks_num = (*forks)[mnum];
		forks_num.thread_num = 0;
		s = pthread_mutex_init(&forks_num.mutex_id, NULL);
		if (s != 0)
			return (error_message("pthread_mutex_init"));
	}
	return (0);
}

int	set_table(t_table_info *table, t_simulation_info *sinfo)
{
	table->philos = (t_thread_info *) \
			malloc(sinfo->number * sizeof(t_thread_info));
	if (table->philos == NULL)
		return (error_message("malloc"));
	table->forks = (t_mutex_info *)malloc(num_mutex * sizeof(**forks));
	if (*forks == NULL)
		return (error_message("malloc"));
	if (set_fork(table->forks, sinfo->number) == -1)
		return (1);
	if (set_philo(table, sinfo) == -1)
		return (1);
	return (0)
}