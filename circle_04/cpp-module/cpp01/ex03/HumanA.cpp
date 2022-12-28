#include "HumanA.hpp"

HumanA::HumanA( std::string name , Weapon& weapon) : _name(name), _weapon(weapon) {
	// std::cout << "\033[0;90m(appear)" << this->_name << " - "  << this->_weapon.getType() << "\033[0m" << std::endl;
}

HumanA::~HumanA() {
	// std::cout << "\033[0;90m(disappear)" << this->_name << "\033[0m" << std::endl;
}

void HumanA::attack(void) const
{
	std::cout << this->_name << " with his " << this->_weapon.getType() << std::endl;	
}
