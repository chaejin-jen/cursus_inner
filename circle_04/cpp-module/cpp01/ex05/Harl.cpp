#include "Harl.hpp"

std::string	Harl::_levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
};

Harl::Harl(void) {}

Harl::~Harl(void) {}

int Harl::printmsg(int i){
	functionPtr	complains = {&Harl::debug, &Harl::info, \
			&Harl::warning, &Harl::error};
	(this->*complains[i])();
	return 0;
}

void Harl::complain( std::string level ){
	int	i(0);

	while (i < LEVEL_NUM && level != Harl::_levels[i])
		i++;
	i < 4 ? this->printmsg(i) : 1;
}

void Harl::debug( void ){
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::info( void ){
	std::cout << INFO_MSG << std::endl;

}

void Harl::warning( void ){
	std::cout << WARNING_MSG << std::endl;

}

void Harl::error( void ){
	std::cout << ERROR_MSG << std::endl;
}