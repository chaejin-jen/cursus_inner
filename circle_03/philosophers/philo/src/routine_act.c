/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:59:44 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/24 19:23:16 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo_info *philo, t_fork_info *finfo,
	t_simulation_info *sinfo)
{
	if (philo->recent_act + sinfo->time_to_eat - sinfo->time_to_sleep
		> philo->start + sinfo->time_to_die)
	{
		sleep_until(philo->start + sinfo->time_to_die);
		return (1);
	}
	pthread_mutex_lock(&finfo[0].mutex_id);
	pthread_mutex_lock(&finfo[1].mutex_id);
	philo->recent_act = timestamp(sinfo, philo->philo_num, TAKE);
	finfo[0].thread_num = philo->philo_num;
	finfo[1].thread_num = philo->philo_num;
	return (0);
}

int	eat(t_philo_info *philo, t_fork_info *finfo, t_simulation_info *sinfo)
{
	pthread_mutex_lock(&sinfo->timer);
	philo->start = timestamp(sinfo, philo->philo_num, EAT);
	pthread_mutex_unlock(&sinfo->timer);
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
	philo->recent_act = timestamp(sinfo, philo->philo_num, SLEEP);
	if (sleep_until_limit(philo->recent_act + sinfo->time_to_sleep,
			philo->start + sinfo->time_to_die))
		return (1);
	philo->recent_act = timestamp(sinfo, philo->philo_num, THINK);
	return (0);
}

void	dying(t_philo_info *philo, t_simulation_info *sinfo)
{
	philo->recent_act = timestamp(sinfo, philo->philo_num, DEAD);
}
