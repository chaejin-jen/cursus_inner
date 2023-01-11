#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
	std::cout << "Default constructor called - ScavTrap" << std::endl;
	this->_setMaxValue();
	ClapTrap::_setStatus("noname");
}

ScavTrap::ScavTrap(std::string name){
	std::cout << "Constructor called (std::string) - ScavTrap" << std::endl;
	this->_setMaxValue();
	ClapTrap::_setStatus(name);
}

ScavTrap::ScavTrap(const ScavTrap& other){
	std::cout << "Copy constructor called - ScavTrap" << std::endl;
	this->_setMaxValue();
	this->_setStatus(other);
}

ScavTrap::~ScavTrap(void){
	std::cout << "Destructor called - ScavTrap" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	std::cout << "Copy assignment operator called - ScavTrap" << std::endl;
	this->_setMaxValue();
	if (this != &other){
		*this = other;
	}
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName()
		<< "is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::_setMaxValue(void){
	ClapTrap::_max_hp = scavtrap::MAX_HP;
	ClapTrap::_max_ep = scavtrap::MAX_EP;
	ClapTrap::_max_ad = scavtrap::MAX_AD;
}

void ScavTrap::_setStatus(const ScavTrap &other){
	
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
}
