#include "HumanB.hpp"

HumanB::HumanB( std::string name) : _name(name), _weapon(NULL) {
	// std::cout << "\033[0;90m(appear)" << this->_name << "\033[0m" << std::endl;
}

HumanB::~HumanB() {
	// std::cout << "\033[0;90m(disappear)" << this->_name << "\033[0m" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	// std::cout << "\033[0;92m(change)" << this->_name << " - " << weapon.getType() << "\033[0m" << std::endl;	
}

void HumanB::attack(void) const
{
	std::cout << this->_name;
	if (this->_weapon) 
		std::cout << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << " couldn't attack without weapon" << std::endl;
}
