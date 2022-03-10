#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	BUFFER_SIZE = 100;

void	check_2(int count, char *s)
{
	while (*s != '\n')
	{
		s++;
	}
	printf("check_2\tcount : %d string : ", count);
	write(1, s, 13);
	write(1, "\n", 1);
}

void	check_1(char *s)
{
	int	count;

	count = 0;
	while(count != 3)
	{
		check_2(count, s);
		printf("check_1\tcount : %d string : ", count);
		write(1, s, 13);
		write(1, "\n", 1);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	char	read_buf[BUFFER_SIZE];
	int		fd;
	int		read_len;

	fd = open(argv[2], O_RDONLY);
	read_len = read(fd, read_buf, BUFFER_SIZE);
	read_buf[read_len] = '\0';
	check_1(read_buf);
}