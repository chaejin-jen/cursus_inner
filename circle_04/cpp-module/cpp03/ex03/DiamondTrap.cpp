#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void){
	std::cout << "Default constructor called - DiamondTrap" << std::endl;
	this->_setMaxValue();
	ClapTrap::_setStatus(std::string("noname") + "_clap_name");
}

DiamondTrap::DiamondTrap(std::string name){
	std::cout << "Default constructor called - DiamondTrap" << std::endl;
	this->_setMaxValue();
	ClapTrap::_setStatus(name + "_clap_name");
}

DiamondTrap::DiamondTrap(const DiamondTrap& other){
	std::cout << "Copy constructor called - DiamondTrap" << std::endl;
	this->_setMaxValue();
	this->_setStatus(other);
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "Destructor called - DiamondTrap" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
	std::cout << "Copy assignment operator called - DiamondTrap" << std::endl;
	this->_setMaxValue();
	if (this != &other){
		*this = other;
	}
	return *this;
}

void	DiamondTrap::_setMaxValue(void){
	ClapTrap::_max_hp = diamondtrap::MAX_HP;
	ClapTrap::_max_ep = diamondtrap::MAX_EP;
	ClapTrap::_max_ad = diamondtrap::MAX_AD;
}

void DiamondTrap::_setStatus(const DiamondTrap &other){
	ClapTrap::_name = other._name + "_clap_name";
	ClapTrap::_hp = other._hp;
	ClapTrap::_ep = other._ep;
	ClapTrap::_ad = other._ad;
}

void DiamondTrap::whoAmI(void){
	std::cout << "\033[1;93m"<< "===============whoAmI?!=============="<<
		"\nClapTrap\t: " << ClapTrap::_name
		<< "\nDiamondTrap\t: " << this->_name
		<< "\n===============================\n\033[0m" << std::endl;
}