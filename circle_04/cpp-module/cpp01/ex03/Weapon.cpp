#include "Weapon.hpp"

// Weapon::Weapon( void ) : _type("body without weapon") {}

Weapon::Weapon( std::string type ) : _type(type) {
	// std::cout << "\033[0;90m(create)" << this->_type << "\033[0m" << std::endl;
}

Weapon::~Weapon( void ) {
	// std::cout << "\033[0;90m(distroy)" << this->_type << "\033[0m" << std::endl;
}

std::string Weapon::getType(void) const
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	// std::cout << "\033[0;92m(change)" << this->_type << " -> " << type << "\033[0m" << std::endl;	
	this->_type = type;
}