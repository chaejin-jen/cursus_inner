/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:17:42 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 19:48:17 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_eating(t_mutex_info *forks, t_thread_info *philos)
{
	pthread_mutex_lock(forks->mutex_id);
	forks->thread_num = philos->thread_num;
	philos->thread_status = EATING;
	printf("timestamp_in_ms %d has taken a fork", philos->thread_num);
	printf("timestamp_in_ms %d is eating", philos->thread_num);
}

int	end_eating(t_mutex_info *forks, t_thread_info *philos)
{
	forks->thread_num = 0;
	pthread_mutex_unlock(forks->mutex_id);
	philos->thread_status = SLEEP;
	printf("timestamp_in_ms %d is sleeping", philos->thread_num);
}

int	ready(t_thread_info *philos)
{
	philos->thread_status = THINK;
	printf("timestamp_in_ms %d is thinking", philos->thread_num);
}

void	*philo_action(void *arg)
{
	t_table_info	*table;
	int				thread_status;
	int				thread_num;
	unsigned int	rest_eat;
	t_time_info		tinfo;

	table = arg;
	thread_num = table->philo_num;
	last_eat_time = philo->last_eat_time;
	while (last_eat_time.tv_sec == 0 && last_eat_time.tv_usec == 0)
		;
	while (philo->rest_eat != 0)
	{
		// if (philo->thread_status == THINK)
		// 	start_eating(philos);
		// if (philo->thread_status == SLEEP)
		// 	end_eating(philo);
		// if ()
		usleep(30);
	}
	return (0);
}
