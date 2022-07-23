/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:54:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/23 13:50:40 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	timestamp(t_simulation_info *sinfo, int philo_num, int state)
{
	static int	need_end = FALSE;
	float			mticks;
	t_tv		current;

	pthread_mutex_lock(&sinfo->printer);
	if (need_end == TRUE)
		return (pthread_mutex_unlock(&sinfo->printer));
	gettimeofday(&current, NULL);
	mticks = time_diff(&sinfo->start, &current);
	if (state == TAKE)
		printf("%10.2f %d has taken a fork\n", mticks, philo_num);
	else if (state == EAT)
		printf("\033[0;33m%10.2f %d is eating\n\033[0m", mticks, philo_num);
	else if (state == SLEEP)
		printf("\033[0;35m%10.2f %d is sleeping\n\033[0m", mticks, philo_num);
	else if (state == THINK)
		printf("\033[0;32m%10.2f %d is thinking\n\033[0m", mticks, philo_num);
	else if (state == DEAD)
	{
		need_end = TRUE;
		printf("\033[0;31m%10.2f %d died\n\033[0m", mticks, philo_num);
	}
	return (pthread_mutex_unlock(&sinfo->printer));
}

int	error_message(char *msg)
{
	printf("\033[0;31mERROR : %s\n\033[0m", msg);
	return (-1);
}
