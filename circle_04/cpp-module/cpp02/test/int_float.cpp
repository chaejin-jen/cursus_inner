#include <iostream>

int	main()
{
	// int a(3079133234567890.f);
	// std::cout << a << std::endl;
	// std::cout << static_cast<int>(3079133234567890.f) << std::endl;
	int a(12345678);

	std::cout << (1 >> 1) << std::endl;
	for (int i = 1 ; i < 50 ; i++){
		// a += (1 >> 1);
		// a += (1 >> 2);
		a += (1 >> i);
		std::cout << a << std::endl;
	}
}