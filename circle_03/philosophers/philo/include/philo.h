/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:09 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/12 04:48:12 by chaejkim         ###   ########.fr       */
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

typedef struct s_simulation_info
{
	pthread_mutex_t	monitor;
	pthread_mutex_t	printer;
	pthread_mutex_t	timer;
	struct timeval	current;
	t_bool			need_end;
	unsigned int	number;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				least_eat;
}				t_simulation_info;

typedef struct s_time_info
{
	struct timeval	last_eat;
	struct timeval	last_act;
	float			time_to_die;
	float			time_to_act;
}				t_time_info;

typedef struct s_fork_info
{
	pthread_mutex_t	mutex_id;
	int				thread_num;
}				t_fork_info;

typedef struct s_philo_info
{
	pthread_t	thread_id;
	int			philo_num;
	int			state;
	int			rest_eat;
	t_fork_info	*finfo;
	t_time_info	tinfo;
}				t_philo_info;

typedef struct s_table_info
{
	t_simulation_info	*sinfo;
	t_philo_info		*philos;
	t_fork_info			*forks;
	int					seat_num;
}				t_table_info;

int		error_message(char *msg);


/* time_info.c */
void	init_time_info(t_time_info *tinfo);
void	update_tinfo(t_time_info *tinfo, struct timeval *current);

int		set_simulation(int argc, char **argv, t_simulation_info *sinfo);

int		set_table(t_table_info *table, const t_simulation_info *sinfo);
int		clear_table(t_table_info *table, int number);

void	*routine(void *arg);

/* routine_util.c */
void	start_eating(t_philo_info *philo, t_fork_info *forks, t_simulation_info *sinfo);
void	end_eating(t_philo_info *philo, t_fork_info *forks, t_simulation_info *sinfo);
void	dying(int philo_num, t_simulation_info *sinfo);

#endif
