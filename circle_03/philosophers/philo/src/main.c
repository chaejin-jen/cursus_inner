/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/08 23:33:27 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *thread_start(void *arg)
{
	t_thread_info	*tinfo;
	char			*uargv;
	char 			*p;

	tinfo = arg;
	//printf("Thread %d: top of stack near %p; argv_string=%s\n",
	//		tinfo->thread_num, (void *) &tinfo, tinfo->argv_string);
	uargv = strdup(tinfo->argv_string);
	if (uargv == NULL)
		handle_error("strdup");

	p = uargv;
	while (*p)
		*p = toupper(*p++);
	return uargv;
}

static int	make_thread(int num_threads)
{
	pthread_attr_t	attr;
	t_thread_info	*tinfo;
	int				s;
	int				tnum;

	tinfo = malloc(num_threads, sizeof(*tinfo));
	if (tinfo == NULL)
		handle_error("calloc");

	tnum = -1;
	while (++tnum < num_threads)
	{
		tinfo[tnum].thread_num = tnum + 1;
		//tinfo[tnum].argv_string = argv[optind + tnum];
		s = pthread_create(&tinfo[tnum].thread_id, &attr,
							&thread_start, &tinfo[tnum]);
		if (s != 0)
			return (error_message("pthread_create"));
	}
	return (0);
}

static int	destroy_thread()
{
	//pthread_attr_t	attr;
	//int				s;

	//s = pthread_attr_destroy(&attr);
	//if (s != 0)
	//		return (error_message("pthread_attr_destroy"));
	//return (0);
	pthread_mutex_destroy();
	//free(tinfo);
}

static int	join_thread(t_thread_info *tinfo, int num_threads)
{
	int		tnum;
	int		s;
	void	*res;

	tnum = -1;
	while (++tnum < num_threads)
	{
		s = pthread_join(*tinfo[tnum].thread_id, &res);
		if (s != 0)
			handle_error_en(s, "pthread_join");

		printf("Joined with thread %d; returned value was %s\n",
				tinfo[tnum].thread_num, (char *) res);
		free(res);      /* Free memory allocated by thread */
	}
}

int	main(int argc, char *argv[])
{
	//number_of_philosophers
	//time_to_die
	//time_to_eat
	//time_to_sleep
	//[number_of_times_each_philosopher_must_eat]
	if (parse_args(argc, argv) == -1)
		return (1);
	make_thread();
	philo();
	destroy_thread();
	memset();
	pthread_detach();
	pthread_mutex_init();
	pthread_mutex_lock();
	pthread_mutex_unlock();
}
