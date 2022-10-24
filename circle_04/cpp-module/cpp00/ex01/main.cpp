#include "PhoneBook.hpp"

int	main(void) {
	std::string	cmd;
	PhoneBook	phonebook;
	Contact	test;

	// test.setIdx(1);
	// std::cout << "getFirstname : " << test.getFirstname() << std::endl; //test
	// std::cout << "getLastname : " << test.getLastname() << std::endl; //test
	// std::cout << "getNickname : " << test.getNickname() << std::endl; //test
	std::cout << "Please enter one of the ADD, SEARCH or EXIT" << std::endl << "> ";
	while (std::getline(std::cin, cmd))
	{
		if (!cmd.compare("ADD")){
			//std::cout << "ADD" << std::endl;
			if (phonebook.add() != 0)
				std::cout << "add contact failed" << std::endl;
		}
		else if (!cmd.compare("SEARCH")){
			//std::cout << "SEARCH" << std::endl;
			phonebook.search();
		}
		else if (!cmd.compare("EXIT")){
			break ;
		}
		std::cout << "Please enter one of the ADD, SEARCH or EXIT" << std::endl << "> ";
	}
	std::cout << "Bye" << std::endl;

	return (0);
}
