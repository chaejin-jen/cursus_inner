#include "Character.hpp"

Character::Character(void) : _name("_"){
	//std::cout << "\033[0;90mDefault constructor called - Character\033[0m" << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		_slot[i] = NULL;
}

Character::Character(std::string name) : _name(name){
	//std::cout << "\033[0;90mConstructor called (std::string) - Character\033[0m" << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		_slot[i] = NULL;
}

Character::Character(const Character& other){
	//std::cout << "\033[0;90mCopy constructor called - Character\033[0m" << std::endl;
	_name = other._name;
	*_slot = *other._slot;
}

Character& Character::operator=(const Character& other){
	//std::cout << "\033[0;90mCopy assignment operator called - Character\033[0m" << std::endl;
	_name = other._name;
	*_slot = *other._slot;
	return *this;
}

Character::~Character(void){
	//std::cout << "\033[0;90mDestructor called - Character\033[0m" << std::endl;
}

std::string const & Character::getName() const{
	return _name;
}
void Character::equip(AMateria* m){
	int i(-1);

	if (m == NULL)
		return ;
	while (++i < 4 && this->_slot[i])
		;
	if (i >= 4){
		//std::cout << "\033[0;90mInventory is full.\033[0m" << std::endl;
		return ;
	}
	this->_slot[i] = m;
	////std::cout << "\033[0;92m" << m->getType() <<  " equiped in slot[" << i << "].\033[0m" << std::endl;
}
void Character::unequip(int idx){
	if (idx < 0 || idx >= 4){
		////std::cout << "\033[0;91mInventory slots are 4. slot number " << idx << " is not available \033[0m" << std::endl;
		return ;
	}
	this->_slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 4 ){
		////std::cout << "\033[0;91mInventory slots are 4. slot number " << idx << " is not available\033[0m" << std::endl;
		return ;
	}
	if (this->_slot[idx] == NULL){
		////std::cout << "\033[0;91mInventory slot number " << idx << " is empty\033[0m" << std::endl;
		return ;
	}
	this->_slot[idx]->use(target);
}
