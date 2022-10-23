#include <iostream>
#include <cstdio>

int		main(int argc, char *argv[]) {
	std::string	str;

	argv++;
	while (*argv)
	{
		str = *argv;
		for (size_t i = 0; i < str.length(); i++){
			str[i] = std::toupper(str[i]);
		}
		std::cout << str;
		argv++;
	}
	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
	return (0);
}
