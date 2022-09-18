#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	errno = 0;
	long maxThreads = sysconf(_SC_THREAD_THREADS_MAX);
	if (maxThreads == -1 && errno == 0)
	{
		printf("the variable corresponding to _SC_THREAD_THREADS_MAX "
				"is associated with functionality that is not "
				"supported by the system\n");
		exit(1);
	}
	if (maxThreads == -1)
	{
		printf("errno: %d\n", errno);
		exit(1);
	}

	printf ("max num threads per process: %ld\n", maxThreads);

	exit(0);
}
