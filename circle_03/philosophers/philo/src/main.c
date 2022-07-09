/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/09 18:16:50 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	make_philo_thread(t_thread_info **tinfo, t_philo_info *pinfo)
{
	int				s;
	int				tnum;
	t_thread_info	tinfo_num;

	*tinfo = (t_thread_info *)malloc(pinfo->number_of_philo * sizeof(**tinfo));
	if (*tinfo == NULL)
		return (error_message("malloc"));
	tnum = -1;
	while (++tnum < pinfo->number_of_philo)
	{
		tinfo_num = (*tinfo)[tnum];
		tinfo_num.thread_num = tnum + 1;
		tinfo_num.least_eat = pinfo->least_eat;
		tinfo_num.thread_status = THINK;
		if (tnum + 1 != pinfo->number_of_philo)
			tinfo_num.r_thread = &(*tinfo)[tnum + 1];
		else
			tinfo_num.r_thread = &(*tinfo)[0];
		s = pthread_create(&tinfo_num.thread_id, NULL,
				&philo_routine, &tinfo_num);
		if (s != 0)
			return (error_message("pthread_create"));
		// pthread_detach(&tinfo_num.thread_id);
	}
	return (0);
}

static int	make_fork_mutex(t_mutex_info **minfo, int num_mutex)
{
	t_mutex_info	minfo_num;
	int				mnum;
	int				s;

	*minfo = (t_mutex_info *)malloc(num_mutex * sizeof(**minfo));
	if (*minfo == NULL)
		return (error_message("malloc"));
	mnum = -1;
	while (++mnum < num_mutex)
	{
		minfo_num = (*minfo)[mnum];
		minfo_num.thread_num = 0;
		s = pthread_mutex_init(&minfo_num.mutex_id, NULL);
		if (s != 0)
			return (error_message("pthread_mutex_init"));
	}
	return (0);
}

static int	destroy_philo_thread(t_thread_info **tinfo, int num_threads)
{
	int				tnum;
	int				s;
	void			*res;
	t_thread_info	tinfo_num;

	tnum = -1;
	while (++tnum < num_threads)
	{
		tinfo_num = (*tinfo)[tnum];
		s = pthread_join(tinfo_num.thread_id, &res);
		if (s != 0)
			return (error_message("pthread_join"));
		// printf("Joined with thread %d; returned value was %s\n",
		// 	tinfo_num.thread_num, (char *) res);
		free(res);
	}
	return (0);
}

static int	destroy_fork_mutex(t_mutex_info **minfo, int num_threads)
{
	int				tnum;
	int				s;
	void			*res;
	t_mutex_info	minfo_num;

	tnum = -1;
	while (++tnum < num_threads)
	{
		minfo_num = (*minfo)[tnum];
		s = pthread_mutex_destroy(&minfo_num);
		if (s != 0)
			return (error_message("pthread_mutex_destroy"));
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philo_info	pinfo;
	t_thread_info	*tinfo;
	t_mutex_info	*minfo;

	if (set_philo_info(argc, argv, &pinfo) == -1)
		return (1);
	if (make_philo_thread(&tinfo, &pinfo) == -1)
		return (1);
	if (make_fork_mutex(&minfo, pinfo.number_of_philo) == -1)
		return (1);
	simulation(&pinfo, tinfo, minfo);
	// memset();
	if (destroy_philo_thread(&tinfo, NULL) == -1)
		return (1);
	if (destroy_fork_mutex(&minfo, NULL) == -1)
		return (1);
	destroy_pinfo();
}
