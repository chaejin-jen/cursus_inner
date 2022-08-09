/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/08/09 22:26:37 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define TAKE "%d %d has taken a fork\n"
# define EAT "\033[0;33m%d %d is eating\n\033[0m"
# define SLEEP "\033[0;35m%d %d is sleeping\n\033[0m"
# define THINK "\033[0;32m%d %d is thinking\n\033[0m"
# define DEAD "\033[0;31m%d %d died\n\033[0m"
# define FINISH "========= simulation finished ==========\n"

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
	long long		start;
	int				number;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				least_eat;
	int				end_number;
}				t_simulation_info;

typedef struct s_fork_info
{
	pthread_mutex_t	mutex_id;
	int				thread_num;
}				t_fork_info;

typedef struct s_philo_info
{
	pthread_t			thread_id;
	int					pnum;
	int					rest_eat;
	long long			recent_eat;
	long long			recent_act;
	t_fork_info			*finfo;
	t_simulation_info	*sinfo;
}				t_philo_info;

typedef struct s_table_info
{
	t_simulation_info	*sinfo;
	t_philo_info		*philos;
	t_fork_info			*forks;
}				t_table_info;

long long	timestamp(t_simulation_info *sinfo,
				int pnum, char *act, t_bool is_end);
int			error_message(char *msg);

/* time.c */
double		time_diff(t_tv *start, t_tv *end);
long long	get_mticks(void);
void		sleep_until(long long end);
int			sleep_until_limit(long long end, long long limit_end);

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
int			monitor(t_table_info *table);

/* routine.c */
void		*routine(void *arg);

/* routine_act.c */
int			take_fork(t_philo_info *philo, t_fork_info *finfo,
				t_simulation_info *sinfo);
int			eat(t_philo_info *philo, t_fork_info *finfo,
				t_simulation_info *sinfo);
int			put_down_fork(t_fork_info *finfo);
int			psleep(t_philo_info *philo, t_simulation_info *sinfo);
void		dying(t_philo_info *philo, t_simulation_info *sinfo);

/* routine_util.c */
void		wait_philos(pthread_mutex_t *timer, long long *start);
void		sync_philos(t_simulation_info *sinfo, t_philo_info *philo);
void		note_end(pthread_mutex_t *monitor, t_simulation_info *sinfo);

#endif
