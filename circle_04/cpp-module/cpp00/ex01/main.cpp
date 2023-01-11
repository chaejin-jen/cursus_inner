#include "PhoneBook.hpp"

int	main(void) {
	std::string	cmd;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Please enter one of the ADD, SEARCH or EXIT" << std::endl << "> ";
		if (!std::getline(std::cin, cmd)){
			std::cout << '\n';
			break;
		}
		if (!cmd.compare("ADD")){
			if (phonebook.add() != 0)
				std::cout << "add contact failed" << std::endl;
		}
		else if (!cmd.compare("SEARCH")){
			phonebook.search();
		}
		else if (!cmd.compare("EXIT")){
			break ;
		}
		if (std::cin.eof())
		{
			std::cin.clear();
			std::clearerr(stdin);
		}
	}
	std::cout << "Bye" << std::endl;

	return (0);
}
