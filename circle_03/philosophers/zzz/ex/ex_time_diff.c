#include <sys/time.h>
#include <time.h>
#include <stdio.h>

#define MAX 1000000

typedef struct timeval	t_tv;
typedef struct timespec	t_ts;

void	tv_time_diff(int i)
{
	t_tv	start, end;
	double	time;
	double	tmp_value;

	tmp_value = 0.0;

	gettimeofday(&start, NULL);
	while (i++ < MAX)
		tmp_value += i;
	gettimeofday(&end, NULL);
	if ((end.tv_usec - start.tv_usec) < 0)
	{
		end.tv_usec += 1000000;
		end.tv_sec -= 1;
	}
	time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	printf("Time (Nano): %lf\n", time * 1000);
	printf("Time (Micro): %lf\n", time);
	printf("Time (Milli): %lf\n", time / 1000);
	printf("Time (Second): %lf\n", time / 1000000);
}

void	ts_time_diff(int i)
{
	t_ts	start, end;
	long	time;
	double 	tmp_value;

	tmp_value = 0.0;

	clock_gettime(CLOCK_MONOTONIC, &start);
	while (i++ < MAX)
		tmp_value += i;
	clock_gettime(CLOCK_MONOTONIC, &end);
	time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);
	if ((end.tv_nsec-start.tv_nsec) < 0)
		time += 999999999;
	printf("Time (Nano): %ld\n", time);
	printf("Time (Micro): %lf\n", (double)time/1000);
	printf("Time (Milli): %lf\n", (double)time/1000000);
	printf("Time (Second): %lf\n", (double)time/1000000000);
}

int	main(void)
{
	tv_time_diff(0);
	printf("\n");
	ts_time_diff(0);
	return (0);
}