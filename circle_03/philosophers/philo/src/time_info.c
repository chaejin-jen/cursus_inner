/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:33:55 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/13 13:04:12 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void msleep(float wait_time)
{
	usleep((int)(wait_time * 1000));
}

void get_timer_time(pthread_mutex_t *timer, struct timeval *tv)
{
	pthread_mutex_lock(timer);
	gettimeofday(tv, NULL);
	pthread_mutex_unlock(timer);
}

float time_diff(struct timeval *start, struct timeval *end)
{
	return (((float)(end->tv_sec - start->tv_sec)) * 1000 \
		+ ((float)(end->tv_usec - start->tv_usec)) / 1000);
}

void set_elasped_time(pthread_mutex_t *timer, t_time_info *tinfo, struct timeval *current)
{
	pthread_mutex_lock(timer);
	tinfo->elasped_time = 0;
	tinfo->last_eat.tv_sec = current->tv_sec;
	tinfo->last_eat.tv_usec = current->tv_usec;
	pthread_mutex_unlock(timer);
}

void update_elasped_time(pthread_mutex_t *timer, t_time_info *tinfo, struct timeval *current)
{
	pthread_mutex_lock(timer);
	tinfo->elasped_time = time_diff(&tinfo->last_eat, current);
	pthread_mutex_unlock(timer);
}
