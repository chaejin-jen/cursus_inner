/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:23:45 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/13 12:59:50 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "stdio.h"

void timestamp(t_simulation_info *sinfo, int philo_num, int state)
{
	float mticks;

	pthread_mutex_lock(&sinfo->timer);
	mticks = time_diff(&sinfo->start, &sinfo->current);
	pthread_mutex_unlock(&sinfo->timer);
	pthread_mutex_lock(&sinfo->printer);
	if (state == TAKE)
		printf("%f %d has taken a fork\n", mticks, philo_num);
	else if (state == EAT)
		printf("%f %d is eating\n", mticks, philo_num);
	else if (state == SLEEP)
		printf("%f %d is sleeping\n", mticks, philo_num);
	else if (state == THINK)
		printf("%f %d is thinking\n", mticks, philo_num);
	else if (state == DEAD)
		printf("%f %d died\n", mticks, philo_num);
	pthread_mutex_unlock(&sinfo->printer);
}

void start_eating(t_philo_info *philo, t_fork_info *forks, t_simulation_info *sinfo)
{
	pthread_mutex_lock(&forks[0].mutex_id);
	pthread_mutex_lock(&forks[1].mutex_id);
	timestamp(sinfo, philo->philo_num, TAKE);
	forks[0].thread_num = philo->philo_num;
	forks[1].thread_num = philo->philo_num;
	if (philo->tinfo.elasped_time < sinfo->time_to_die)
	{
		if (philo->tinfo.elasped_time + sinfo->time_to_eat < sinfo->time_to_die)
		{
			timestamp(sinfo, philo->philo_num, EAT);
			set_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
			msleep(sinfo->time_to_eat);
			update_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
			return;
		}
		msleep(sinfo->time_to_die - philo->tinfo.elasped_time);
		dying(philo->philo_num, sinfo);
		return;
	}
	dying(philo->philo_num, sinfo);
}

void end_eating(t_philo_info *philo, t_fork_info *forks, t_simulation_info *sinfo)
{
	forks[0].thread_num = 0;
	forks[1].thread_num = 0;
	pthread_mutex_unlock(&forks[0].mutex_id);
	pthread_mutex_unlock(&forks[1].mutex_id);
	philo->rest_eat--;
	if (philo->tinfo.elasped_time < sinfo->time_to_die)
	{
		if (philo->tinfo.elasped_time + sinfo->time_to_sleep < sinfo->time_to_die)
		{
			timestamp(sinfo, philo->philo_num, SLEEP);
			update_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
			msleep(sinfo->time_to_sleep);
			timestamp(sinfo, philo->philo_num, THINK);
			update_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
			return;
		}
		msleep(sinfo->time_to_die - philo->tinfo.elasped_time);
		dying(philo->philo_num, sinfo);
		return;
	}
	dying(philo->philo_num, sinfo);
}

void dying(int philo_num, t_simulation_info *sinfo)
{
	pthread_mutex_lock(&sinfo->monitor);
	sinfo->need_end = TRUE;
	pthread_mutex_unlock(&sinfo->monitor);
	timestamp(sinfo, philo_num, DEAD);
}
