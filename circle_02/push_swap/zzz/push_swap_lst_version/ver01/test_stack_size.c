#include <stdio.h>

#include <limits.h>

static long	ft_strtol(const char *str)
{
	long	sign;
	long	tmp;
	long	sum;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	sum = 0;
	tmp = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = (sum * 10) + sign * (*str - '0');
		if (sum > 0 && tmp < 0)
			return (LONG_MAX);
		if (sum < 0 && tmp > 0)
			return (LONG_MIN);
		sum = tmp;
		str++;
	}
	return (sum);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str));
}

void	print_size(int n, int depth);

int	top_size(int n, int depth)
{
	if (n > 3)
		print_size((int)(n / 3 + n % 3), depth + 1);
	printf("====top====\n");
	return (n);
}

int	mid_size(int n, int depth)
{
	if (n > 3)
		print_size((int)(n / 3), depth + 1);
	printf("====mid====\n");
	return (n);
}

void	print_size(int n, int depth)
{
	printf("depth: %d\t top: %d\n", depth, top_size((int)(n / 3 + n % 3), depth));
	printf("depth: %d\t mid: %d\n", depth, mid_size((int)(n / 3), depth));
}

int	main(int argc, char *argv[])
{
	int	n;
	int	top;
	int	mid;

	if (argc != 2)
	{
		printf("argv need\n");
		return (-1);
	}
	n = ft_atoi(argv[1]);
	print_size(n, 0);
	//top = (int)(n / 3 + n % 3);
	//mid = (int)(n / 3);
	//printf("======n: %d \tn%%3: %d=======\n", n, n % 3);
	//while (top > 3)
	//{
	//	printf("TOP: %d\t", top);
	//	printf("MID: %d\n", mid);
	//	top = (int)(top / 3 + top % 3);
	//	mid = (int)(mid / 3);
	//}
	//printf("TOP: %d\t", top);
	//printf("MID: %d\n", mid);
	//int i = 20;
	//while (i++ != 100)
	//{
	//	printf("./test_stack_size %d\n", i);
	//}
}
