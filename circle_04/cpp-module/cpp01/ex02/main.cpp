#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "string(address)    : " << &string << '\n';
	std::cout << "stringPTR(address) : " << stringPTR << '\n';
	std::cout << "stringREF(address) : " << &stringREF << std::endl;

	std::cout << "string             : " << string << '\n';
	std::cout << "stringPTR(string)  : " << *stringPTR << '\n';
	std::cout << "stringREF(string)  : " << stringREF << std::endl;

	return 0;
}
