#include "Harl.hpp"

int	main(void)
{
	Harl h;

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");

	h.complain("xsdfvcfghj");
	h.complain("ERROR_");
	return 0;
}