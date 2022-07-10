/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 20:39:11 by chaejkim         ###   ########.fr       */
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

/* Used as simulation condition*/
typedef struct s_cond_info
{
	unsigned int	number;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	least_eat;
}				t_cond_info;

typedef struct s_time_info
{
	struct timeval	last_eat;
	struct timeval	cur;
	float			time_to_dead;
}				t_time_info;

typedef struct s_philo_info
{
	pthread_t	thread_id;
	int			philo_num;
	int			philo_state;
}				t_philo_info;

typedef struct s_fork_info
{
	pthread_mutex_t	mutex_id;
	int				thread_num;
}				t_fork_info;

typedef struct s_simulation_info
{
	t_philo_info	*philo;
	t_fork_info		*left_fork;
	t_fork_info		*right_fork;
	t_time_info		*tinfo;
	t_cond_info		*param;
}				t_simulation_info;

int		error_message(char *msg);

float	time_diff(struct timeval *start, struct timeval *end);
void	init_time_info(t_time_info *tinfo);
void	update_run_time(t_time_info *tinfo);
void	update_execute_time(t_time_info *tinfo);

int		set_simulation(int argc, char **argv, t_simulation_info *sinfo);

int		clear_table(t_table_info *table, int number);

void	*philo_routine(void *arg);

#endif
