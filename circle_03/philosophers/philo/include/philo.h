/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/23 13:44:22 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_status
{
	THINK,
	TAKE,
	EAT,
	SLEEP,
	DEAD
}			t_status;

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct timeval	t_tv;

typedef struct s_simulation_info
{
	pthread_mutex_t	monitor;
	pthread_mutex_t	printer;
	pthread_mutex_t	timer;
	t_tv			start;
	t_bool			need_end;
	int				number;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				least_eat;
}				t_simulation_info;

typedef struct s_fork_info
{
	pthread_mutex_t	mutex_id;
	int				thread_num;
}				t_fork_info;

typedef struct s_philo_info
{
	pthread_t	thread_id;
	int			philo_num;
	int			rest_eat;
	t_fork_info	*finfo;
	long long	start;
}				t_philo_info;

typedef struct s_table_info
{
	t_simulation_info	*sinfo;
	t_philo_info		*philos;
	t_fork_info			*forks;
	int					seat_num;
}				t_table_info;

int			timestamp(t_simulation_info *sinfo, int philo_num, int state);
int			error_message(char *msg);

/* time.c */
float		time_diff(t_tv *start, t_tv *end);
long long	get_nticks(void);
void		msleep(long long end);
int			limit_msleep(long long end, long long limit_end);

/* run.c */
int			run_simulation(t_simulation_info *sinfo);

/* simulation_info.c */
int			set_simulation_info(int argc, char **argv,
				t_simulation_info *sinfo);
int			clear_simulation_info(t_simulation_info *sinfo);

/* table_info.c */
int			set_table(t_table_info *table, t_simulation_info *sinfo);
int			clear_table(t_table_info *table, int number);

/* monitor.c */
int			monitor(t_simulation_info *sinfo);

/* routine.c */
void		*routine(void *arg);

/* routine_act.c */
int			take_fork(t_philo_info *philo, t_fork_info *finfo,
				t_simulation_info *sinfo);
int			eat(t_philo_info *philo, t_fork_info *finfo,
				t_simulation_info *sinfo);
int			put_down_fork(t_fork_info *finfo);
int			psleep(t_philo_info *philo, t_simulation_info *sinfo);
void		dying(int philo_num, t_simulation_info *sinfo);

/* routine_util.c */
void		wait_philos(pthread_mutex_t *timer, t_simulation_info *sinfo);
void		sync_philos(t_simulation_info *sinfo, t_philo_info *philo);
int			check_end(t_simulation_info *sinfo, t_philo_info *philo);
void		note_end(pthread_mutex_t *monitor, t_simulation_info *sinfo);

#endif
