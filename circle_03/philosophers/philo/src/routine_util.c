/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:23:45 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/14 22:39:19 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_eating(t_philo_info *philo, t_fork_info *finfo,
	t_simulation_info *sinfo)
{
	pthread_mutex_lock(&finfo[0].mutex_id);
	pthread_mutex_lock(&finfo[1].mutex_id);
	timestamp(sinfo, philo->philo_num, TAKE);
	finfo[0].thread_num = philo->philo_num;
	finfo[1].thread_num = philo->philo_num;
	if (philo->tinfo.elasped_time < sinfo->time_to_die)
	{
		timestamp(sinfo, philo->philo_num, EAT);
		if (philo->tinfo.elasped_time + sinfo->time_to_eat < sinfo->time_to_die)
		{
			set_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
			msleep(sinfo->time_to_eat);
			update_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
			return (0);
		}
		update_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
		msleep(sinfo->time_to_die - philo->tinfo.elasped_time);
	}
	pthread_mutex_unlock(&finfo[0].mutex_id);
	pthread_mutex_unlock(&finfo[1].mutex_id);
	return (1);
}

int	end_eating(t_philo_info *philo, t_fork_info *finfo,
	t_simulation_info *sinfo)
{
	finfo[0].thread_num = 0;
	finfo[1].thread_num = 0;
	pthread_mutex_unlock(&finfo[0].mutex_id);
	pthread_mutex_unlock(&finfo[1].mutex_id);
	if (philo->rest_eat != -1)
		philo->rest_eat--;
	if (philo->tinfo.elasped_time < sinfo->time_to_die)
	{
		timestamp(sinfo, philo->philo_num, SLEEP);
		if (philo->tinfo.elasped_time + sinfo->time_to_sleep \
			< sinfo->time_to_die)
		{
			msleep(sinfo->time_to_sleep);
			timestamp(sinfo, philo->philo_num, THINK);
			update_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
			return (0);
		}
		update_elasped_time(&sinfo->timer, &philo->tinfo, &sinfo->current);
		msleep(sinfo->time_to_die - philo->tinfo.elasped_time);
	}
	return (1);
}

void	dying(int philo_num, t_simulation_info *sinfo)
{
	pthread_mutex_lock(&sinfo->monitor);
	if (sinfo->need_end == FALSE)
		timestamp(sinfo, philo_num, DEAD);
	sinfo->need_end = TRUE;
	pthread_mutex_unlock(&sinfo->monitor);
}

void	wait_philos(pthread_mutex_t *timer,
		t_simulation_info *sinfo, t_philo_info *philo)
{
	while (1)
	{
		pthread_mutex_lock(timer);
		if (sinfo->current.tv_sec != 0 || sinfo->current.tv_usec != 0)
		{
			pthread_mutex_unlock(timer);
			break ;
		}
		pthread_mutex_unlock(timer);
		usleep(20);
	}
	if (philo->philo_num % 2)
		usleep(50);
	usleep(50);
}

int	check_die(pthread_mutex_t *monitor,
	t_simulation_info *sinfo, t_philo_info *philo)
{
	pthread_mutex_lock(monitor);
	if (sinfo->need_end == TRUE)
	{
		pthread_mutex_unlock(monitor);
		return (1);
	}
	pthread_mutex_unlock(monitor);
	if (philo->tinfo.elasped_time > sinfo->time_to_die)
	{
		dying(philo->philo_num, sinfo);
		return (1);
	}
	return (0);
}
