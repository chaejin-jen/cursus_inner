#include "PhoneBook.hpp"

int		main(void) {
	std::string		cmd;

	while (1)
	{
		std::cout << "Please enter one of ADD, SEARCH or EXIT" << std::endl << "> ";
		std::cin >> cmd;
		if (!cmd.compare("ADD")){
			std::cout << "ADD" << std::endl;
		}
		else if (!cmd.compare("SEARCH")){
			std::cout << "SEARCH" << std::endl;
		}
		else if (!cmd.compare("EXIT")){
			std::cout << "Bye" << std::endl;
			break ;
		}
	}
	return (0);
}
