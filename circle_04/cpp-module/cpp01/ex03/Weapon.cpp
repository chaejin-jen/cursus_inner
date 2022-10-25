#include "Weapon.hpp"

// Weapon::Weapon( void ) : _type("body without weapon") {}

Weapon::Weapon( std::string type ) : _type(type) {
	std::cout << "(create)" << this->_type << std::endl;
}

Weapon::~Weapon( void ) {
	std::cout << "(distroy)" << this->_type << std::endl;
}

std::string Weapon::getType(void) const
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}