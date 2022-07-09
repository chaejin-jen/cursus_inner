/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:17:42 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/09 16:02:50 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_thread_info		*tinfo;

	tinfo = arg;
	while (tinfo->least_eat !=0)
	{
		usleep(30);
	}
	return (0);
}
