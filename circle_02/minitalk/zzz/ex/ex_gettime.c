#include <time.h>
#include <stdio.h>

#define MAX 1000000

int	main(void)
{
	struct timespec	start, end;
	double 			tmp_value;
	int				i;

	tmp_value = 0.0;

	clock_gettime(CLOCK_MONOTONIC, &start);
	i = 0;
	while (i++ < MAX)
		tmp_value += i;
	clock_gettime(CLOCK_MONOTONIC, &end);
	long	time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);
	if ((end.tv_nsec-start.tv_nsec) < 0)
		time += 999999999;
	printf("Time (Nano): %ld\n", time);
	printf("Time (Micro): %lf\n", (double)time/1000);
	printf("Time (Milli): %lf\n", (double)time/1000000);
	printf("Time (Second): %lf\n", (double)time/1000000000);
	return (0);
}
