/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:59:44 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/20 16:45:22 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo_info *philo, t_fork_info *finfo,
	t_simulation_info *sinfo)
{
	if (sinfo->number == 1)
	{
		philo->recent_act = timestamp(sinfo, philo->pnum, TAKE, FALSE);
		sleep_until(philo->recent_eat + sinfo->time_to_die);
		dying(philo, sinfo);
		return (1);
	}
	if (philo->recent_act + sinfo->time_to_eat - sinfo->time_to_sleep
		> philo->recent_eat + sinfo->time_to_die)
	{
		sleep_until(philo->recent_eat + sinfo->time_to_die);
		dying(philo, sinfo);
		return (1);
	}
	pthread_mutex_lock(finfo[0].mutex_id);
	pthread_mutex_lock(finfo[1].mutex_id);
	if (get_mticks() > philo->recent_eat + sinfo->time_to_die)
	{
		dying(philo, sinfo);
		return (put_down_fork(finfo) + 1);
	}
	philo->recent_act = timestamp(sinfo, philo->pnum, TAKE, FALSE);
	finfo[0].thread_num = philo->pnum;
	finfo[1].thread_num = philo->pnum;
	return (0);
}

int	eat(t_philo_info *philo, t_fork_info *finfo, t_simulation_info *sinfo)
{
	pthread_mutex_lock(&sinfo->timer);
	philo->recent_eat = timestamp(sinfo, philo->pnum, EAT, FALSE);
	philo->recent_act = philo->recent_eat;
	pthread_mutex_unlock(&sinfo->timer);
	if (sleep_until_limit(philo->recent_eat + sinfo->time_to_eat,
			philo->recent_eat + sinfo->time_to_die))
	{
		dying(philo, sinfo);
		return (put_down_fork(finfo) + 1);
	}
	return (0);
}

int	put_down_fork(t_fork_info *finfo)
{
	finfo[0].thread_num = 0;
	finfo[1].thread_num = 0;
	pthread_mutex_unlock(finfo[0].mutex_id);
	pthread_mutex_unlock(finfo[1].mutex_id);
	return (0);
}

int	psleep(t_philo_info *philo, t_simulation_info *sinfo)
{
	if (philo->rest_eat != -1)
		philo->rest_eat--;
	philo->recent_act = timestamp(sinfo, philo->pnum, SLEEP, FALSE);
	if (philo->rest_eat == 0)
	{
		note_end(&sinfo->monitor, sinfo);
		philo->rest_eat = -1;
	}
	if (sleep_until_limit(philo->recent_act + sinfo->time_to_sleep,
			philo->recent_eat + sinfo->time_to_die))
	{
		dying(philo, sinfo);
		return (1);
	}
	philo->recent_act = timestamp(sinfo, philo->pnum, THINK, FALSE);
	return (0);
}

void	dying(t_philo_info *philo, t_simulation_info *sinfo)
{
	philo->recent_act = timestamp(sinfo, philo->pnum, DEAD, TRUE);
}
