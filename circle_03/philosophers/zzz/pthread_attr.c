/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_attr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/09 16:02:01 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	make_philo_thread(t_thread_info **tinfo, pthread_attr_t *attr,
						const t_philo_info *pinfo)
{
	int				s;
	int				tnum;
	t_thread_info	tinfo_num;

	*tinfo = malloc(pinfo->number_of_philo, sizeof(**tinfo));
	if (*tinfo == NULL)
		return (error_message("malloc"));
	tnum = -1;
	while (++tnum < pinfo->number_of_philo)
	{
		tinfo_num = (*tinfo)[tnum];
		tinfo_num.thread_num = tnum + 1;
		tinfo_num.thread_status = READY;
		s = pthread_create(&tinfo_num.thread_id, &attr,
				&philo_routine, pinfo);
		if (s != 0)
			return (error_message("pthread_create"));
		// pthread_detach(&tinfo_num.thread_id);
	}
	return (0);
}

static int	make_fork_mutex(t_thread_info **tinfo, 


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

int	main(int argc, char *argv[])
{
	t_thread_info	*tinfo;
	t_philo_info	pinfo;
	t_mutex_info	*minfo;

	if (set_philo_info(argc, argv, &pinfo) == -1)
		return (1);
	if (make_philo_thread(&tinfo, NULL, &pinfo) == -1)
		return (1);
	if ((make_fork_mutex(&minfo, pinfo.number_of_philo)) == -1)
	if (destroy_philo_thread(&tinfo, NULL) == -1)
		return (1);
	destroy_pinfo();
}

void	*philo_routine(void *arg)
{
	t_thread_info		*tinfo;
	// t_philo_info	*pinfo;
	// char			*keep;

	while ()
	{
		/* code */
	}
	
	//printf("Thread %d: top of stack near %p; argv_string=%s\n",
	//		tinfo->thread_num, (void *) &tinfo, tinfo->argv_string);
	// memset();
	// pthread_mutex_init();
	// pthread_mutex_lock();
	// pthread_mutex_unlock();
	// keep = malloc(keep);
	tinfo = arg;
	tinfo->least_eat;
	while (tinfo->least_eat !=0)
	{
		usleep(30);
	}
	return (0);
	// return (keep);
}
