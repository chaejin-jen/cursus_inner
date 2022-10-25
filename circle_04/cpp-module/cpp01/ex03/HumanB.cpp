#include "HumanB.hpp"

HumanB::HumanB( std::string name) : _name(name) {
	std::cout << "(appear)" << this->_name << std::endl;
}

HumanB::~HumanB() {
	std::cout << "(disappear)" << this->_name << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	std::cout << "(change)" << this->_name << " - " << weapon.getType() << std::endl;	
}

void HumanB::attack(void) const
{
	std::cout << this->_name << " with his " << this->_weapon->getType() << std::endl;	
}
