#include <stdio.h>

int	main(void)
{
	int	cnt = 0;
	int	i = 2147483647;

	while (++cnt < 2)
	{
		if (i > (i * 1000L))
			printf("INT_MAX > INT_MAX * 1000 \n");
		if (i < (i * 1000L))
			printf("INT_MAX < INT_MAX * 1000 \n");
		printf("%ld ", (i * 1000L));
	}
	printf("\n%d\n", cnt);
}
