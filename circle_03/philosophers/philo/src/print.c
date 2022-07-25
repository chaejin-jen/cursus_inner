/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:54:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/25 20:59:31 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

long long	timestamp(t_simulation_info *sinfo, int pnum, int act)
{
	static int	any_dead = FALSE;
	double		mticks;
	long long	current;

	pthread_mutex_lock(&sinfo->printer);
	if (any_dead == TRUE)
		return (pthread_mutex_unlock(&sinfo->printer));
	current = get_mticks();
	mticks = (current - sinfo->start) / 1000.;
	if (act == TAKE)
		printf("%10.2f %d has taken a fork\n", mticks, pnum);
	else if (act == EAT)
		printf("\033[0;33m%10.2f %d is eating\n\033[0m", mticks, pnum);
	else if (act == SLEEP)
		printf("\033[0;35m%10.2f %d is sleeping\n\033[0m", mticks, pnum);
	else if (act == THINK)
		printf("\033[0;32m%10.2f %d is thinking\n\033[0m", mticks, pnum);
	else if (act == DEAD)
	{
		any_dead = TRUE;
		if (pnum != 0)
			printf("\033[0;31m%10.2f %d died\n\033[0m", mticks, pnum);
		return (pthread_mutex_unlock(&sinfo->printer));
	}
	return (pthread_mutex_unlock(&sinfo->printer) + current);
}

int	error_message(char *msg)
{
	printf("\033[0;31mERROR : %s\n\033[0m", msg);
	return (-1);
}
