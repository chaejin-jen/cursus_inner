/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:54:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/22 16:15:17 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	timestamp(t_simulation_info *sinfo, int philo_num, int state)
{
	static int	need_end = FALSE;
	int			mticks;
	t_tv		current;

	pthread_mutex_lock(&sinfo->printer);
	if (need_end == TRUE)
		return (pthread_mutex_unlock(&sinfo->printer));
	gettimeofday(&current, NULL);
	mticks = time_diff(&sinfo->start, &current);
	if (state == TAKE)
		printf("%d %d has taken a fork\n", mticks, philo_num);
	else if (state == EAT)
		printf("\033[0;33m%d %d is eating\n\033[0m", mticks, philo_num);
	else if (state == SLEEP)
		printf("%d %d is sleeping\n", mticks, philo_num);
	else if (state == THINK)
		printf("\033[0;32m%d %d is thinking\n\033[0m", mticks, philo_num);
	else if (state == DEAD)
	{
		need_end = TRUE;
		printf("\033[0;31m%d %d died\n\033[0m", mticks, philo_num);
	}
	return (pthread_mutex_unlock(&sinfo->printer));
}

int	error_message(char *msg)
{
	printf("\033[0;31mERROR : %s\n\033[0m", msg);
	return (-1);
}
