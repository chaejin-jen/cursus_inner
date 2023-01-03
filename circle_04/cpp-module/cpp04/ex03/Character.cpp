#include "Character.hpp"

Character::Character(void) : _name("_"){
	std::cout << "\033[0;90mDefault constructor called - Character\033[0m" << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name){
	std::cout << "\033[0;90mConstructor called (std::string) - Character\033[0m" << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other){
	std::cout << "\033[0;90mCopy constructor called - Character\033[0m" << std::endl;
	_name = other._name;
	*_inventory = other._inventory;
}

Character& Character::operator=(const Character& other){
	std::cout << "\033[0;90mCopy assignment operator called - Character\033[0m" << std::endl;
	_name = other._name;
	*_inventory = other._inventory;
	return *this;
}

Character::~Character(void){
	std::cout << "\033[0;90mDestructor called - Character\033[0m" << std::endl;
}

std::string const & Character::getName() const{
	return _name;
}
void Character::equip(AMateria* m){
	(void)m;
}
void Character::unequip(int idx){
	(void)idx;
}
void Character::use(int idx, Character& target){
	(void)idx;
	(void)target;
}
