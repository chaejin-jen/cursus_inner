#include "Harl.hpp"

int main(int ac, char* av[])
{
	if (ac != 2)
		return (0);

	Harl h;
	h.complain(av[1]);
	return 0;
}