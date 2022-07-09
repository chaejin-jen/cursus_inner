/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/09 18:11:33 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_status
{
	THINK,
	EATING,
	SLEEP,
	DEAD
}			t_status;

/* Used as argument to thread_start() 
 *   thread_id   : ID returned by pthread_create()
 *   thread_num  : Application-defined thread #
 *   argv_string : From command-line argument
 */

typedef struct s_thread_info
{
	pthread_t				thread_id;
	int						thread_num;
	int						thread_status;
	unsigned int			least_eat;
	struct s_thread_info	*r_thread;
}				t_thread_info;

typedef struct s_mutex_info
{
	pthread_mutex_t	mutex_id;
	int				thread_num;
}				t_mutex_info;

typedef struct s_philo_info
{
	unsigned int	number_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	least_eat;
}				t_philo_info;

int		error_message(char *msg);
int		set_philo_info(int argc, char **argv, t_philo_info *pinfo);
void	*philo_routine(void *arg);

#endif
