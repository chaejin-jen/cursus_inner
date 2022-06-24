#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char			*s;
	int				bit_num;
	int				received;
	unsigned char	req;

	if (argc < 2)
		return (-1);
	s = argv[1];
	while (*s)
	{
		received = 0;
		req = 0;
		bit_num = 1;
		while (bit_num < UCHAR_MAX)
		{
			if (*s & bit_num)
			{
				write(1, "1", 1);
				req |= bit_num;
			}
			else
				write(1, "0", 1);
			bit_num = bit_num << 1;
			received++;
		}
		printf("\nreceived : %d\n", received);
		printf("req : %c\n\n", req);
		s++;
	}
	return (0);
}
