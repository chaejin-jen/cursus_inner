/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:54:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/14 22:16:19 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	timestamp(t_simulation_info *sinfo, int philo_num, int state)
{
	static int	need_end = FALSE;
	float		mticks;

	pthread_mutex_lock(&sinfo->printer);
	if (need_end == TRUE)
		return (pthread_mutex_unlock(&sinfo->printer));
	pthread_mutex_lock(&sinfo->timer);
	mticks = time_diff(&sinfo->start, &sinfo->current);
	pthread_mutex_unlock(&sinfo->timer);
	if (state == TAKE)
		printf("%f %d has taken a fork\n", mticks, philo_num);
	else if (state == EAT)
		printf("%f %d is eating\n", mticks, philo_num);
	else if (state == SLEEP)
		printf("%f %d is sleeping\n", mticks, philo_num);
	else if (state == THINK)
		printf("%f %d is thinking\n", mticks, philo_num);
	else if (state == DEAD)
	{
		need_end = TRUE;
		printf("%f %d died\n", mticks, philo_num);
	}
	return (pthread_mutex_unlock(&sinfo->printer));
}

int	error_message(char *msg)
{
	printf("\033[0;31mERROR : %s\n\033[0m", msg);
	return (-1);
}
