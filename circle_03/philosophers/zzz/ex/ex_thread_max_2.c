#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>

#include <limits.h>
void * ThreadFunc( void * pclsArg )
{
 sleep(1000);

 return NULL;
}

int	main( int argc, char * argv[] )
{
	int iCount = 0;
	pthread_t *iThread;

	iThread = (pthread_t *)malloc(sizeof(pthread_t));
	while( iCount <= 8191)
	{
		if( pthread_create( iThread, NULL, ThreadFunc, NULL ) != 0 )
		{
			printf( "error = %d\n", errno );
			break;
		}
		pthread_detach( *iThread );
		++iCount;
		printf( "%d\n", iCount );
	}
	return 0;
}
