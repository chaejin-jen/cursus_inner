// If the first operand is an int or uint (32-bit quantity), the shift count is given by the low-order five bits of the second operand. That is, the actual shift count is 0 to 31 bits.
// If the first operand is a long or ulong (64-bit quantity), the shift count is given by the low-order six bits of the second operand. That is, the actual shift count is 0 to 63 bits.

#include <iostream>

int	main()
{

	std::cout << (1 >> 5) << std::endl;

	std::cout << (1 << -5) << std::endl;
	std::cout << (1 >> -5) << std::endl;

	std::cout << (1 << 5) << std::endl;
}