/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:53:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/09 18:02:16 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	stop_philo(t_table_info *table, t_simulation_info *sinfo, int tnum)
{
	timestamp(sinfo, 0, DEAD, TRUE);
	sinfo->start = get_mticks();
	usleep(1000);
	clear_table(table, tnum);
	return (error_message("pthread_create"));
}

static int	set_fork(t_fork_info **forks, int n_fork)
{
	int			fnum;
	int			s;

	*forks = (t_fork_info *)malloc((n_fork + 1) * sizeof(t_fork_info));
	if (*forks == NULL)
		return (error_message("malloc (forks)"));
	fnum = -1;
	while (++fnum < n_fork)
	{
		(*forks)[fnum].thread_num = 0;
		s = pthread_mutex_init(&(*forks)[fnum].mutex_id, NULL);
		if (s != 0)
			return (error_message("pthread_mutex_init (fork)"));
	}
	(*forks)[fnum].mutex_id = (*forks)[0].mutex_id;
	(*forks)[fnum].thread_num = (*forks)[0].thread_num;
	return (0);
}

static int	set_philo(t_table_info *table, t_philo_info **philos, int n_philo)
{
	int				tnum;
	t_philo_info	*pinfo;

	*philos = (t_philo_info *) malloc(n_philo * sizeof(t_philo_info));
	if (*philos == NULL)
		return (error_message("malloc (philos)"));
	tnum = -1;
	pthread_mutex_lock(&table->sinfo->timer);
	while (++tnum < n_philo)
	{
		pinfo = &((*philos)[tnum]);
		pinfo->sinfo = table->sinfo;
		if (pthread_create(&pinfo->thread_id, NULL, &routine, (void *)pinfo))
			return (stop_philo(table, table->sinfo, tnum - 1));
		pinfo->pnum = tnum + 1;
		pinfo->rest_eat = table->sinfo->least_eat;
		pinfo->finfo = &table->forks[tnum];
		memset((void *)&pinfo->recent_eat, 0x7f, sizeof(long long));
		pinfo->recent_act = pinfo->recent_eat;
	}
	pthread_mutex_unlock(&table->sinfo->timer);
	return (0);
}

int	set_table(t_table_info *table, t_simulation_info *sinfo)
{
	table->sinfo = sinfo;
	if (set_fork(&table->forks, sinfo->number) == -1)
		return (1);
	if (set_philo(table, &table->philos, sinfo->number) == -1)
		return (1);
	return (0);
}

int	clear_table(t_table_info *table, int number)
{
	t_philo_info	*philos;
	t_fork_info		*forks;
	int				num;
	int				s;

	num = -1;
	philos = table->philos;
	forks = table->forks;
	while (++num < number)
	{
		s = pthread_join(philos[num].thread_id, NULL);
		if (s != 0)
			return (error_message("pthread_join"));
	}
	num = -1;
	number++;
	while (++num < number)
	{
		s = pthread_mutex_destroy(&forks[num].mutex_id);
		if (s != 0)
			return (error_message("pthread_mutex_destroy"));
	}
	free(forks);
	free(philos);
	return (0);
}
