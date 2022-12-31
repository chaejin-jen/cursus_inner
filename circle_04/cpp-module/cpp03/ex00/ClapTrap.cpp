#include "ClapTrap.hpp"
#include <iomanip>

ClapTrap::ClapTrap(void) : _name("unnamed"), _hp(claptrap::MAX_HP), 
	_ep(claptrap::MAX_EP), _ad(claptrap::MAX_AD){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(claptrap::MAX_HP), 
	_ep(claptrap::MAX_EP), _ad(claptrap::MAX_AD){
	std::cout << "Constructor called (std::string)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if (_hp == 0){
		std::cout << "\033[0;90mClapTrap " << _name 
			<< " already died! (acting failed)\033[0m" << std::endl;
		return ;
	}
	if (_ep == 0){
		std::cout << "\033[0;90mClapTrap " << _name 
			<< " has 0 EP! (acting failed)\033[0m" << std::endl;
		return ;
	}
	_ep--;
	std::cout << "\033[0;96mClapTrap " << _name << " attacks "
		<< target << ", causing " << _ad << " points of damage!\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hp == 0){
		_hp = 0;
		std::cout << "\033[0;90m"<< _name << " already died!\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[0;31m" << "ClapTrap " << _name << " damaged "
		<< amount << " points of damage!\033[0m" << std::endl;
	if (_hp < amount){
		_hp = 0;
		std::cout << "\033[1;31m"<< _name << " died!\033[0m" << std::endl;
		return ;
	}
	_hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hp == 0){
		std::cout << "\033[0;90mClapTrap " << _name 
			<< " already died! (acting failed)\033[0m" << std::endl;
		return ;
	}
	if (_ep == 0){
		std::cout << "\033[0;90mClapTrap " << _name 
			<< " has 0 EP! (acting failed)\033[0m" << std::endl;
		return ;
	}
	if (_hp == claptrap::MAX_HP){
		std::cout << "\033[0;90m" << _name << " hp is already full!\033[0m" << std::endl;
		return ;
	}
	else if (amount >= claptrap::MAX_HP || _hp + amount >= claptrap::MAX_HP)
		_hp = 10;
	else
		_hp += amount;
	_ep--;
	std::cout << "\033[0;92mClapTrap " << _name << " repaires "
		<< amount << " points of hit points!"
		<< "(hit points : " << _hp << ")\033[0m" << std::endl;
}

std::string ClapTrap::getName(void) const{
	return _name;
}

unsigned int ClapTrap::getHitPoints(void) const{
	return _hp;
}

unsigned int ClapTrap::getAttackDamage(void) const{
	return _ad;
}

void ClapTrap::putStatus(void) const{
	unsigned int	w = _name.length();

	w < 5 ? w = 5 : true;
	std::cout << "+-" << std::string(w + 2, '-') << "-+\n| ";
	std::cout.width(w + 2);
	std::cout.fill(' ');
	std::cout<< _name << " |\n";
	std::cout << "+-" << std::string(w + 2, '-') << "-+\n| HP";
	std::cout.width(w);
	std::cout.fill(' ');
	std::cout << _hp << " |\n| EP";
	std::cout.width(w);
	std::cout.fill(' ');
	std::cout << _ep << " |\n| AD";
	std::cout.width(w);
	std::cout.fill(' ');
	std::cout << _ad << " |\n";
	std::cout << "+-" << std::string(w + 2, '-') << "-+\n";
}