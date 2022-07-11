/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:22:48 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 04:01:39 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timestamp(t_simulation_info *sinfo, int philo_num, int state)
{
	pthread_mutex_lock(&sinfo->printer);
	pthread_mutex_lock(&sinfo->timer);
	if (state == TAKE)
		printf("%ld %d has taken a fork", sinfo->current, philo_num);
	if (state == EAT)
		printf("%ld %d is eating", sinfo->current, philo_num);
	if (state == SLEEP)
		printf("%ld %d is sleeping", sinfo->current, philo_num);
	if (state == THINK)
		printf("%ld %d is thinking", sinfo->current, philo_num);
	if (state == DEAD)
		printf("%ld %d died", sinfo->current, philo_num);
	pthread_mutex_unlock(&sinfo->timer);
	pthread_mutex_unlock(&sinfo->printer);
}

int	monitor(t_table_info *table, t_simulation_info *sinfo, int number)
{
	static int	philo_done = 0;

	if (philo_done == number)
		return (0);
	pthread_mutex_lock(&sinfo->monitor);
	if (sinfo->need_end == TRUE)
		return (0);
	pthread_mutex_unlock(&sinfo->monitor);
	return (1);
}
