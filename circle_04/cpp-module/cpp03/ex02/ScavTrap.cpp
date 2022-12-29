#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
	std::cout << "Default constructor called - ScavTrap" << std::endl;
	this->_setMaxValue();
	ClapTrap::_setStatus("noname");
}

ScavTrap::ScavTrap(std::string name){
	std::cout << "Default constructor called - ScavTrap" << std::endl;
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
	
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
}


// void ScavTrap::attack(const std::string& target){
// 	if (_ep == 0){
// 		std::cout << "\033[0;90mScavTrap " << _name 
// 			<< " has 0 EP! (acting failed)\033[0m" << std::endl;
// 		return ;
// 	}
// 	_ep--;
// 	std::cout << "\033[0;96mScavTrap " << _name << " attacks "
// 		<< target << ", causing " << _ad << " points of damage!\033[0m" << std::endl;
// }

// void ScavTrap::takeDamage(unsigned int amount){
// 	if (_hp == 0){
// 		_hp = 0;
// 		std::cout << "\033[0;90m"<< _name << " already died!\033[0m" << std::endl;
// 		return ;
// 	}
// 	std::cout << "\033[0;31m" << "ScavTrap " << _name << " damaged "
// 		<< amount << " points of damage!\033[0m" << std::endl;
// 	if (_hp < amount){
// 		_hp = 0;
// 		std::cout << "\033[1;31m"<< _name << " died!\033[0m" << std::endl;
// 		return ;
// 	}
// 	_hp -= amount;
// }

// void ScavTrap::beRepaired(unsigned int amount){
// 	if (_ep == 0){
// 		std::cout << "\033[0;90mScavTrap " << _name 
// 			<< " has 0 EP! (acting failed)\033[0m" << std::endl;
// 		return ;
// 	}
// 	if (_hp == ScavTrap::MAX_HP){
// 		std::cout << "\033[0;90m" << _name << " hp is already full!\033[0m" << std::endl;
// 		return ;
// 	}
// 	else if (amount >= ScavTrap::MAX_HP || _hp + amount >= ScavTrap::MAX_HP)
// 		_hp = 10;
// 	else
// 		_hp += amount;
// 	std::cout << "\033[0;92mScavTrap " << _name << " repaires "
// 		<< amount << " points of hit points!"
// 		<< "(hit points : " << _hp << ")\033[0m" << std::endl;
// }

// std::string ScavTrap::getName(void) const{
// 	return _name;
// }

// unsigned int ScavTrap::getHitPoints(void) const{
// 	return _hp;
// }

// unsigned int ScavTrap::getAttackDamage(void) const{
// 	return _ad;
// }

// void ScavTrap::putStatus(void) const{
// 	unsigned int	w = _name.length();

// 	w < 5 ? w = 5 : true;
// 	std::cout << "+-" << std::string(w + 2, '-') << "-+\n| ";
// 	std::cout.width(w + 2);
// 	std::cout.fill(' ');
// 	std::cout<< _name << " |\n";
// 	std::cout << "+-" << std::string(w + 2, '-') << "-+\n| HP";
// 	std::cout.width(w);
// 	std::cout.fill(' ');
// 	std::cout << _hp << " |\n| EP";
// 	std::cout.width(w);
// 	std::cout.fill(' ');
// 	std::cout << _ep << " |\n| AD";
// 	std::cout.width(w);
// 	std::cout.fill(' ');
// 	std::cout << _ad << " |\n";
// 	std::cout << "+-" << std::string(w + 2, '-') << "-+\n";
// }