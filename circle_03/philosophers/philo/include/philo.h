/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/08 23:14:39 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/* Used as argument to thread_start() */
typedef struct s_thread_info
{
	pthread_t	thread_id;		/* ID returned by pthread_create() */
	int			thread_num;		/* Application-defined thread # */
	char		*argv_string;	/* From command-line argument */
}				t_thread_info;

int	error_message(char *msg);
int	parse_args(int argc, char **argv);

#endif
