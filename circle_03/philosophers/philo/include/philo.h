/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/13 14:34:45 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

typedef enum e_status
{
	THINK,
	TAKE,
	EAT,
	SLEEP,
	DEAD
} t_status;

typedef enum e_bool
{
	FALSE,
	TRUE
} t_bool;

typedef struct s_simulation_info
{
	pthread_mutex_t monitor;
	pthread_mutex_t printer;
	pthread_mutex_t timer;
	struct timeval start;
	struct timeval current;
	t_bool need_end;
	int number;
	float time_to_die;
	float time_to_eat;
	float time_to_sleep;
	float least_eat;
} t_simulation_info;

typedef struct s_time_info
{
	struct timeval last_eat;
	float elasped_time;
} t_time_info;

typedef struct s_fork_info
{
	pthread_mutex_t mutex_id;
	int thread_num;
} t_fork_info;

typedef struct s_philo_info
{
	pthread_t thread_id;
	int philo_num;
	int rest_eat;
	t_fork_info *finfo;
	t_time_info tinfo;
} t_philo_info;

typedef struct s_table_info
{
	t_simulation_info *sinfo;
	t_philo_info *philos;
	t_fork_info *forks;
	int seat_num;
} t_table_info;

void timestamp(t_simulation_info *sinfo, int philo_num, int state);
int error_message(char *msg);

/* time_info.c */
void msleep(float wait_time);
float time_diff(struct timeval *start, struct timeval *end);
void get_timer_time(pthread_mutex_t *timer, struct timeval *tv);
void set_elasped_time(pthread_mutex_t *timer, t_time_info *tinfo, struct timeval *current);
void update_elasped_time(pthread_mutex_t *timer, t_time_info *tinfo, struct timeval *current);

/* run.c */
int run_simulation(t_simulation_info *sinfo);

/* table_info.c */
int set_table(t_table_info *table, t_simulation_info *sinfo);
int clear_table(t_table_info *table, int number);

/* monitor.c */
int monitor(t_simulation_info *sinfo);

/* routine.c */
void *routine(void *arg);

/* routine_util.c */
void start_eating(t_philo_info *philo, t_fork_info *forks, t_simulation_info *sinfo);
void end_eating(t_philo_info *philo, t_fork_info *forks, t_simulation_info *sinfo);
void dying(int philo_num, t_simulation_info *sinfo);
void wait_philos(pthread_mutex_t *timer, t_simulation_info *sinfo, t_philo_info *philo);
int check_die(pthread_mutex_t *monitor, t_simulation_info *sinfo, t_philo_info *philo);

#endif
