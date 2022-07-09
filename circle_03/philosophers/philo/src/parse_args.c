/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:13:33 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/08 16:56:26 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>
#include <sys/syslimits.h>
#include <kern/thread.h>
#include <kern/thread_call.h>
#include <kern/thread_group.h>

static int	ft_atoi()
{

}

static int	is_all_num(const char *s)
{
	while (*s++)
	{
		if (*s < '0' || *s > '9')
			return (0);
	}
	return (1);
}

int	parse_args(int argc, char **argv)
{
	int	i;

	if (argc < 5)
		return (error_message("CHECK ARGUMENTS"));
	i = 0;
	while (++i < 5)
	{
		if ( is_all_num(argv[i]))

	}
	return (1);
}
