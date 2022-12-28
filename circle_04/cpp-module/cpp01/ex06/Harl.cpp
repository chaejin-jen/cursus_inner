#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::complain( std::string level ){
	
	switch (std::string(harl::lvChecker).find("[" + level + "]")){
		case harl::DEBUG:
			this->debug();
			break;
		case harl::INFO:
			this->info();
			break;
		case harl::WARNING:
			this->warning();
			break;
		case harl::ERROR:
			this->error();
			break;
		default:
			break;
	}
}

void Harl::debug( void ){
	std::cout << harl::debugMsg << std::endl;
}

void Harl::info( void ){
	std::cout << harl::infoMsg << std::endl;

}

void Harl::warning( void ){
	std::cout << harl::warnMsg << std::endl;

}

void Harl::error( void ){
	std::cout << harl::errMsg << std::endl;
}