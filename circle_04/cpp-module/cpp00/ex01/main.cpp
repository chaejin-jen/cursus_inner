#include "PhoneBook.hpp"

int		main(void) {
	std::string	cmd;
	PhoneBook	phonebook;

	std::cout << "Please enter one of the ADD, SEARCH or EXIT" << std::endl << "> ";
	while (std::getline(std::cin, cmd))
	{
		if (!cmd.compare("ADD")){
			//std::cout << "ADD" << std::endl;
			phonebook.add();
		}
		else if (!cmd.compare("SEARCH")){
			//std::cout << "SEARCH" << std::endl;
			phonebook.search();
		}
		else if (!cmd.compare("EXIT")){
			std::cout << "Bye" << std::endl;
			break ;
		}
		std::cout << "Please enter one of the ADD, SEARCH or EXIT" << std::endl << "> ";
	}
	return (0);
}
