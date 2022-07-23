/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:59:44 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/23 15:56:43 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo_info *philo, t_fork_info *finfo,
	t_simulation_info *sinfo)
{
	if (get_nticks() + sinfo->time_to_eat - sinfo->time_to_sleep
		> philo->start + sinfo->time_to_die)
	{
		sleep_until(philo->start + sinfo->time_to_die);
		return (1);
	}
	pthread_mutex_lock(&finfo[0].mutex_id);
	pthread_mutex_lock(&finfo[1].mutex_id);
	timestamp(sinfo, philo->philo_num, TAKE);
	finfo[0].thread_num = philo->philo_num;
	finfo[1].thread_num = philo->philo_num;
	return (0);
}

int	eat(t_philo_info *philo, t_fork_info *finfo, t_simulation_info *sinfo)
{
	timestamp(sinfo, philo->philo_num, EAT);
	philo->start = get_nticks();
	if (sleep_until_limit(philo->start + sinfo->time_to_eat,
			philo->start + sinfo->time_to_die))
		return (put_down_fork(finfo) + 1);
	return (0);
}

int	put_down_fork(t_fork_info *finfo)
{
	finfo[0].thread_num = 0;
	finfo[1].thread_num = 0;
	pthread_mutex_unlock(&finfo[0].mutex_id);
	pthread_mutex_unlock(&finfo[1].mutex_id);
	return (0);
}

int	psleep(t_philo_info *philo, t_simulation_info *sinfo)
{
	if (philo->rest_eat != -1)
		philo->rest_eat--;
	timestamp(sinfo, philo->philo_num, SLEEP);
	if (sleep_until_limit(get_nticks() + sinfo->time_to_sleep,
			philo->start + sinfo->time_to_die))
		return (1);
	timestamp(sinfo, philo->philo_num, THINK);
	return (0);
}

void	dying(int philo_num, t_simulation_info *sinfo)
{
	if (sinfo->need_end == FALSE)
	{
		pthread_mutex_lock(&sinfo->monitor);
		timestamp(sinfo, philo_num, DEAD);
		sinfo->need_end = TRUE;
		pthread_mutex_unlock(&sinfo->monitor);
	}
}
