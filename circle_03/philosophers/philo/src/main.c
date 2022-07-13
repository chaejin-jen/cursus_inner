/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/13 10:51:19 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

/* string to positive integer */
static int	ft_strtopi(const char *str)
{
	long		sum;
	const char	*s;

	sum = 0;
	s = str;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	while (*str)
	{
		sum = (sum * 10) + (*str - '0');
		if (sum > INT_MAX)
			return (0);
		str++;
	}
	return ((int)sum);
}

static void	set_num_in_info(t_simulation_info *sinfo, unsigned int num, int i)
{
	if (i == 1)
		sinfo->number = num;
	else if (i == 2)
		sinfo->time_to_die = num;
	else if (i == 3)
		sinfo->time_to_eat = num;
	else if (i == 4)
		sinfo->time_to_sleep = num;
	else if (i == 5)
		sinfo->least_eat = num;
}

static int	set_simulation_info(int argc, char **argv, t_simulation_info *sinfo)
{
	int				i;
	unsigned int	num;

	if (argc < 5 || argc > 6)
		return (error_message("number of arguments"));
	if (pthread_mutex_init(&sinfo->monitor, NULL)
		&& pthread_mutex_init(&sinfo->printer, NULL)
		&& pthread_mutex_init(&sinfo->timer, NULL))
		error_message("pthread_mutex_init (monitor/printer/timer)");
	i = 0;
	while (++i < argc)
	{
		num = ft_strtopi(argv[i]);
		if (num <= 0)
			return (error_message("argument value"));
		set_num_in_info(sinfo, num, i);
	}
	if (argc == 5)
		sinfo->least_eat = -1;
	sinfo->need_end = FALSE;
	memset(&sinfo->current, 0, sizeof(struct timeval));
	return (0);
}

static int	clear_simulation_info(t_simulation_info *sinfo)
{
	pthread_mutex_destroy(&sinfo->monitor);
	pthread_mutex_destroy(&sinfo->printer);
	pthread_mutex_destroy(&sinfo->timer);
	return (0);
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
