#include "philo.h"

int	take_fork(t_philo_info *philo, t_fork_info *finfo,
	t_simulation_info *sinfo)
{
	if (get_nticks() + sinfo->time_to_eat > philo->start + sinfo->time_to_die)
		return (limit_msleep(philo->start + sinfo->time_to_die,
					philo->start + sinfo->time_to_die));
	pthread_mutex_lock(&finfo[0].mutex_id);
	pthread_mutex_lock(&finfo[1].mutex_id);
	timestamp(sinfo, philo->philo_num, TAKE);
	finfo[0].thread_num = philo->philo_num;
	finfo[1].thread_num = philo->philo_num;
	return (0);
}

int	take_fork(t_philo_info *philo, t_fork_info *finfo,
	t_simulation_info *sinfo)
{
	int	is_over;

	is_over = FALSE;
	if (get_elasped_time(philo->start) + sinfo->time_to_eat > sinfo->time_to_die)
		is_over = TRUE;
	pthread_mutex_lock(&finfo[0].mutex_id);
	pthread_mutex_lock(&finfo[1].mutex_id);
	if (is_over == TRUE)
		return (put_down_fork(finfo) + 1);
	timestamp(sinfo, philo->philo_num, TAKE);
	finfo[0].thread_num = philo->philo_num;
	finfo[1].thread_num = philo->philo_num;
	return (0);
}

int	take_fork(t_philo_info *philo, t_fork_info *finfo,
	t_simulation_info *sinfo)
{
	static int	is_first = TRUE;

	if (is_first == FALSE && (get_elasped_time(philo->start)
			+ sinfo->time_to_eat > sinfo->time_to_die))
		return(limit_msleep(philo->start + sinfo->time_to_die, 0));
	if (is_first == TRUE)
		is_first = FALSE;
	pthread_mutex_lock(&finfo[0].mutex_id);
	pthread_mutex_lock(&finfo[1].mutex_id);
	timestamp(sinfo, philo->philo_num, TAKE);
	finfo[0].thread_num = philo->philo_num;
	finfo[1].thread_num = philo->philo_num;
	return (0);
}
