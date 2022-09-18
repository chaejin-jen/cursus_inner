/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_attr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 13:48:10 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	make_philo_thread(t_thread_info **philo_info, pthread_attr_t *attr,
						const t_philo_info *pinfo)
{
	int				s;
	int				tnum;
	t_thread_info	philo_info_num;

	*philo_info = malloc(pinfo->number_of_philo, sizeof(**philo_info));
	if (*philo_info == NULL)
		return (error_message("malloc"));
	tnum = -1;
	while (++tnum < pinfo->number_of_philo)
	{
		philo_info_num = (*philo_info)[tnum];
		philo_info_num.thread_num = tnum + 1;
		philo_info_num.thread_status = READY;
		s = pthread_create(&philo_info_num.thread_id, &attr,
				&philo_routine, pinfo);
		if (s != 0)
			return (error_message("pthread_create"));
		// pthread_detach(&philo_info_num.thread_id);
	}
	return (0);
}

static int	make_fork_mutex(t_thread_info **philo_info, 


static int	destroy_philo_thread(t_thread_info **philo_info, int num_threads)
{
	int				tnum;
	int				s;
	void			*res;
	t_thread_info	philo_info_num;

	tnum = -1;
	while (++tnum < num_threads)
	{
		philo_info_num = (*philo_info)[tnum];
		s = pthread_join(philo_info_num.thread_id, &res);
		if (s != 0)
			return (error_message("pthread_join"));
		// printf("Joined with thread %d; returned value was %s\n",
		// 	philo_info_num.thread_num, (char *) res);
		free(res);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_thread_info	*philo_info;
	t_philo_info	pinfo;
	t_mutex_info	*fork_info;

	if (set_philo_info(argc, argv, &pinfo) == -1)
		return (1);
	if (make_philo_thread(&philo_info, NULL, &pinfo) == -1)
		return (1);
	if ((make_fork_mutex(&fork_info, pinfo.number_of_philo)) == -1)
	if (destroy_philo_thread(&philo_info, NULL) == -1)
		return (1);
	destroy_pinfo();
}

void	*philo_routine(void *arg)
{
	t_thread_info		*philo_info;
	// t_philo_info	*pinfo;
	// char			*keep;

	while ()
	{
		/* code */
	}
	
	//printf("Thread %d: top of stack near %p; argv_string=%s\n",
	//		philo_info->thread_num, (void *) &philo_info, philo_info->argv_string);
	// memset();
	// pthread_mutex_init();
	// pthread_mutex_lock();
	// pthread_mutex_unlock();
	// keep = malloc(keep);
	philo_info = arg;
	philo_info->least_eat;
	while (philo_info->least_eat !=0)
	{
		usleep(30);
	}
	return (0);
	// return (keep);
}
