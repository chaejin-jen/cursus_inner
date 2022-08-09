/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:54:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/09 17:29:08 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

long long	timestamp(t_simulation_info *sinfo,
		int pnum, char *act, t_bool is_end)
{
	static int	any_dead = FALSE;
	long long	current;

	pthread_mutex_lock(&sinfo->printer);
	if (any_dead == TRUE)
		return (pthread_mutex_unlock(&sinfo->printer));
	current = get_mticks();
	if (*act == '=')
		printf("%s", act);
	else
		printf(act, current - sinfo->start, pnum);
	if (is_end == TRUE)
	{
		any_dead = TRUE;
		current = 0;
	}
	return (pthread_mutex_unlock(&sinfo->printer) + current);
}

int	error_message(char *msg)
{
	printf("\033[0;31mERROR : %s\n\033[0m", msg);
	return (-1);
}
