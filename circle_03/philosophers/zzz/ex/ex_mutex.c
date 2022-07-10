#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#ifndef NUM_THREADS
#define NUM_THREADS 20
#endif

int				shared = 0;
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

void	*func3(void *param)
{
	int	i;

	pthread_mutex_lock(&mutex);
	// printf("Incrementing the shared variable...\n");
	i = -1;
	while (++i < 100)
	{
		shared += 1;
		printf("%d ", *(int *)param);
	}
	pthread_mutex_unlock(&mutex);
	return (0);
}

int	main(void)
{
	int			i;
	int			arr[NUM_THREADS];
	pthread_t	threads[NUM_THREADS];

	i = -1;
	while (++i < NUM_THREADS)
	{
		arr[i] = i;
		pthread_create(&threads[i], NULL, func3, &arr[i]);
	}

	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i], NULL);

	printf("\n%d\n", shared);
	exit(EXIT_SUCCESS);
}