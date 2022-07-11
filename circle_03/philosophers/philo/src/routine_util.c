/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:23:45 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 04:49:17 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philo_info *philo, t_fork_info *forks, t_simulation_info *sinfo)
{
	pthread_mutex_lock(&forks[0].mutex_id);
	pthread_mutex_lock(&forks[1].mutex_id);
	timestamp(sinfo, philo->philo_num, TAKE);
	forks[0].thread_num = philo->philo_num;
	forks[1].thread_num = philo->philo_num;
	timestamp(sinfo, philo->philo_num, EAT);
	if (philo->tinfo.time_to_die + sinfo->time_to_eat < sinfo->time_to_die)
	{
		msleep(sinfo->time_to_eat);
		return ;
	}
	msleep(sinfo->time_to_die - philo->tinfo.time_to_die);
	dying(philo->philo_num, sinfo);
}
void	end_eating(t_philo_info *philo, t_fork_info *forks, t_simulation_info *sinfo)
{
	forks[0].thread_num = 0;
	forks[1].thread_num = 0;
	pthread_mutex_unlock(&forks[0].mutex_id);
	pthread_mutex_unlock(&forks[1].mutex_id);
	philo->rest_eat--;
	timestamp(sinfo, philo->philo_num, SLEEP);
	if (philo->tinfo.time_to_die + sinfo->time_to_sleep < sinfo->time_to_die)
	{
		msleep(sinfo->time_to_eat);
		timestamp(sinfo, philo->philo_num, THINK);
		return ;
	}
	msleep(sinfo->time_to_die - philo->tinfo.time_to_die);
	dying(philo->philo_num, sinfo);
}

void	dying(int philo_num, t_simulation_info *sinfo)
{
	pthread_mutex_lock(&sinfo->monitor);
	sinfo->need_end = TRUE;
	pthread_mutex_unlock(&sinfo->monitor);
	timestamp(sinfo, philo_num, DEAD);
	return ;
}
