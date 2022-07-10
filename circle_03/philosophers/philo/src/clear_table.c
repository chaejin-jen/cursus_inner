/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:13:28 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 17:13:50 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	destroy_philo_thread(t_thread_info **philos, int num_threads)
{
	int				tnum;
	int				s;
	void			*res;
	t_thread_info	pinfo;

	tnum = -1;
	while (++tnum < num_threads)
	{
		pinfo = (*philos)[tnum];
		s = pthread_join(pinfo.thread_id, &res);
		if (s != 0)
			return (error_message("pthread_join"));
		// printf("Joined with thread %d; returned value was %s\n",
		// 	pinfo.thread_num, (char *) res);
		free(res);
	}
	return (0);
}

static int	destroy_fork_mutex(t_mutex_info **forks, int num_mutex)
{
	int				tnum;
	int				s;
	void			*res;
	t_mutex_info	forks_num;

	tnum = -1;
	while (++tnum < num_threads)
	{
		forks_num = (*forks)[tnum];
		s = pthread_mutex_destroy(&forks_num);
		if (s != 0)
			return (error_message("pthread_mutex_destroy"));
	}
	return (0);
}

int	clear_table(t_table_info *table, int number)
{
	if (destroy_philo_thread(&philos, number) == -1)
		return (1);
	if (destroy_fork_mutex(&forks, number) == -1)
		return (1);
}
