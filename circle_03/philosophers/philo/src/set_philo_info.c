/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:13:33 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/09 15:37:06 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

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

int	set_philo_info(int argc, char **argv, t_philo_info *pinfo)
{
	int				i;
	unsigned int	num;

	if (argc < 5 || argc > 6)
		return (error_message("number of arguments\n\
			hint: 5 30 3 2 \"4 6 3 10 7\"\nor\n\t5 30 3 2"));
	i = 0;
	while (++i < argc)
	{
		num = ft_strtoui(argv[i]);
		if (num == 0)
			return (error_message("argument value"));
		if (i == 1)
		pinfo->number_of_philo = num;
		else if (i == 2)
			pinfo->time_to_die = num;
		else if (i == 3)
			pinfo->time_to_eat = num;
		else if (i == 4)
			pinfo->time_to_eat = num;
		else if (i == 5)
			pinfo->least_eat = num;
	}
	if (argc == 5)
		pinfo->least_eat = -1;
	return (0);
}
