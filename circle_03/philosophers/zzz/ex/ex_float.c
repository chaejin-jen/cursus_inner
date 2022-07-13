#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	float	f_1, f_2;
	int		i_1, i_2;
	int		cnt;

	if (argc != 2)
	{
		printf("ERROR : ./a.out <숫자>\n");
		return (1);
	}
	f_1 = (float)atoi(argv[1]);
	i_1 = atoi(argv[1]);
	//f_2 = 700000000;
	//i_2 = 700000000;
	f_1--;
	f_2 = 1.1;
	i_2 = 1;
	cnt = -1;
	while (++cnt < 11)
	{
		f_1 += f_2;
		i_1 += i_2;
		if (f_1 == i_1)
			printf("%f == %d\n", f_1, i_1);
		else if (f_1 < i_1)
			printf("%f < %d\n", f_1, i_1);
		if (f_1 > i_1)
			printf("%f > %d\n", f_1, i_1);
	}
	return (0);
}
