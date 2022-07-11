/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:13:33 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 03:53:47 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

static int init_tools_mutex(t_simulation_info *sinfo)
{
	if (pthread_mutex_init(&sinfo->monitor, NULL))
		error_message("pthread_mutex_init (monitor)");
	if (pthread_mutex_init(&sinfo->printer, NULL))
		error_message("pthread_mutex_init (printer)");
	if (pthread_mutex_init(&sinfo->timer, NULL))
		error_message("pthread_mutex_init (timer)");
	return (0);
}

static unsigned int	ft_strtoui(const char *str)
{
	long	sum;
	char	*s;

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
	return ((unsigned int)sum);
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

int	set_simulation(int argc, char **argv, t_simulation_info *sinfo)
{
	int				i;
	unsigned int	num;

	if (argc < 5 || argc > 6)
		return (error_message("number of arguments"));
	if (init_tools_mutex(&sinfo) != 0)
		return (1);
	i = 0;
	while (++i < argc)
	{
		num = ft_strtoui(argv[i]);
		if (num == 0)
			return (error_message("argument value"));
		set_num_in_info(sinfo, num, i);
	}
	if (argc == 5)
		sinfo->least_eat = -1;
	sinfo->need_end = FALSE;
	memset(&sinfo->current, 0, sizeof(struct timeval));
	return (0);
}
