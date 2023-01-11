#include <iostream>
#include <string>

int	main()
{
	std::string a("abc");
	std::string b("abc");
	std::string c("abd");

	std::cout << (a == b) << std::endl;
	std::cout << (b == c) << std::endl;
	std::cout << (a == c) << std::endl;
}