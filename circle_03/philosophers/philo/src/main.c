/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 03:57:12 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_simulation_info(t_simulation_info *sinfo)
{
	pthread_mutex_destroy(&sinfo->monitor);
	pthread_mutex_destroy(&sinfo->printer);
	pthread_mutex_destroy(&sinfo->timer);
}

int	main(int argc, char *argv[])
{
	t_simulation_info	sinfo;

	if (set_simulation_info(argc, argv, &sinfo) != 0)
		return (1);
	if (run_simulation(&sinfo) != 0)
		return (1);
	if (clear_simulation_info(&sinfo) != 0)
		return (1);
	return (0);
}
