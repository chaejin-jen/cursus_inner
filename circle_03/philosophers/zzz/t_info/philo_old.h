/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 20:13:10 by chaejkim         ###   ########.fr       */
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

typedef struct s_simulation_info
{
	unsigned int	number;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	least_eat;
}				t_simulation_info;

typedef struct s_time_info
{
	struct timeval	start;
	struct timeval	cur;
	struct timeval	end;
	float			time_to_dead;
}				t_time_info;

/* Used as argument to thread_start() 
 *   thread_id   : ID returned by pthread_create()
 *   thread_num  : Application-defined thread #
 */
typedef struct s_thread_info
{
	pthread_t	thread_id;
	int			thread_num;
}				t_thread_info;

typedef struct s_philo_info
{
	pthread_t	thread_id;
	int			philo_num;
	t_time_info		tinfo;
}				t_philo_info;

typedef struct s_mutex_info
{
	pthread_mutex_t	mutex_id;
	int				thread_num;
}				t_mutex_info;

typedef struct s_table_info
{
	t_thread_info	*philos;
	t_mutex_info	*forks;
	int				philo_num;
	int				
}				t_table_info;

typedef struct s_seat_info
{
	t_thread_info	*philos;
	t_mutex_info	*forks;
}

int		error_message(char *msg);

float	time_diff(struct timeval *start, struct timeval *end);
void	init_time_info(t_time_info *tinfo);
void	update_run_time(t_time_info *tinfo);
void	update_execute_time(t_time_info *tinfo);

int		set_simulation(int argc, char **argv, t_simulation_info *sinfo);

int		clear_table(t_table_info *table, int number);



void	*philo_routine(void *arg);

#endif
