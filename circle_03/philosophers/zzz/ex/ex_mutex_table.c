
#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_thread_info
{
	pthread_t	thread_id;
	int			thread_num;
}				t_thread_info;

typedef struct s_mutex_info
{
	pthread_mutex_t	mutex_id;
	int				thread_num;
}				t_mutex_info;

typedef struct s_table_info
{
	t_thread_info	philo;
	t_mutex_info	forks[2];
}				t_table_info;

// typedef struct s_seat_info
// {
// 	t_thread_info	philo;
// 	t_mutex_info	forks[2];
// }				t_seat_info;

void	*func3(void *param)
{
	int	i;
	t_table_info	*table;
	int	p_num;

	table = param;
	p_num = table->philo.thread_num;
	pthread_mutex_lock(&table->forks->mutex_id);
	printf("table number : %d\n", table->philo.thread_num);
	printf("Incrementing the shared variable...\n");
	i = -1;
	while (++i < 10)
	{
		usleep(100);
		table->forks[0].thread_num++;
		printf("table nb : %d, fork : %d\n", p_num, table->forks[0].thread_num);
	}
	pthread_mutex_unlock(&table->forks->mutex_id);
	return (0);
}

static int	set_fork(t_mutex_info **forks, int num_mutex)
{
	t_mutex_info	forks_num;
	int				mnum;
	int				s;

	mnum = -1;
	while (++mnum < num_mutex)
	{
		forks_num = (*forks)[mnum];
		forks_num.thread_num = mnum + 1;
		s = pthread_mutex_init(&forks_num.mutex_id, NULL);
		if (s != 0)
			return (printf("pthread_mutex_init"));
	}
	return (0);
}

static int	set_philo(t_thread_info *philos, t_mutex_info *forks, int number)
{
	int				s;
	int				tnum;
	int				prev;
	int				next;
	t_table_info	table;
	t_thread_info	philo;

	tnum = -1;
	while (++tnum < number)
	{
		prev = tnum - 1;
		next = tnum + 1;
		if (prev < 0)
			prev = number;
		if (next > number)
			next = 0;
		philo = philos[tnum];
		philo.thread_num = tnum;
		table.philo = philo;
		table.forks[0] = forks[prev];
		table.forks[1] = forks[next];
		s = pthread_create(&philo.thread_id, NULL, &func3, &table);
		usleep(1);
		if (s != 0)
			return (printf("\npthread_create\n"));
		pthread_detach(philo.thread_id);
	}
	return (0);
}

int	main(void)
{
	t_thread_info	*philos;
	t_mutex_info	*forks;
	id_t			number;

	number = 5;
	philos = (t_thread_info *) malloc(number * sizeof(t_thread_info));
	forks = (t_mutex_info *)malloc(number * sizeof(t_mutex_info));
	set_fork(&forks, number);
	set_philo(philos, forks, number);
	while (1)
	{
		;
	}
	exit(EXIT_SUCCESS);
}