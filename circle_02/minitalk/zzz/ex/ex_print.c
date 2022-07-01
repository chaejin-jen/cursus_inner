#include <unistd.h>

int	main(void)
{
	write(1, "adsfdsaf", 9);
	write(1, "\r", 1);
	write(1, "def", 3);
	//write(1, "ghi", 3);
	//write(1, "\n", 1);
	//write(1, "\v", 1);
	//write(1, "\f", 1);
	//write(1, "\r", 1);
	//write(1, "\n", 1);
}
