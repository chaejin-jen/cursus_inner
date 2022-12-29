#include "FragTrap.hpp"

FragTrap::FragTrap(void){
	std::cout << "Default constructor called - FragTrap" << std::endl;
	this->_setMaxValue();
	ClapTrap::_setStatus("noname");
}

FragTrap::FragTrap(std::string name){
	std::cout << "Default constructor called - FragTrap" << std::endl;
	this->_setMaxValue();
	ClapTrap::_setStatus(name);
}

FragTrap::FragTrap(const FragTrap& other){
	std::cout << "Copy constructor called - FragTrap" << std::endl;
	this->_setMaxValue();
	this->_setStatus(other);
}

FragTrap::~FragTrap(void){
	std::cout << "Destructor called - FragTrap" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	std::cout << "Copy assignment operator called - FragTrap" << std::endl;
	this->_setMaxValue();
	if (this != &other){
		*this = other;
	}
	return *this;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << this->getName()
		<< ": \"Give me five! ✋\"\n" << std::endl;
}

void	FragTrap::_setMaxValue(void){
	this->_max_hp = fragtrap::MAX_HP;
	this->_max_ep = fragtrap::MAX_EP;
	this->_max_ad = fragtrap::MAX_AD;
}

void FragTrap::_setStatus(const FragTrap &other){
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
}
