#include <unistd.h>

int	main(void)
{
	write(1, "\033[0;31m", 8); //Set the text to the color red.
	write(1, "red\n", 7); //Display Hello in red.
	write(1, "\033[0m", 5); //Resets the text to default color
	write(1, "white\n", 7);
}