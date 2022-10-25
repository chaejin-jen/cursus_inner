#include "HumanA.hpp"

HumanA::HumanA( std::string name , Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << "(appear)" << this->_name << " - "  << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "(disappear)" << this->_name << std::endl;
}

void HumanA::attack(void) const
{
	std::cout << this->_name << " with his " << this->_weapon.getType() << std::endl;	
}
