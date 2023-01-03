#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat"){
	std::cout << "\033[0;90mDefault constructor called - WrongCat\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.getType()){
	std::cout << "\033[0;90mCopy constructor called - WrongCat\033[0m" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
	std::cout << "\033[0;90mCopy assignment operator called - WrongCat\033[0m" << std::endl;
	this->_type = other.getType();
	return *this;
}

WrongCat::~WrongCat(void){
	std::cout << "\033[0;90mDestructor called - WrongCat\033[0m" << std::endl;
}

std::string const & WrongCat::getType(void) const{
	return WrongAnimal::_type;
}

void WrongCat::makeSound(void) const{
	std::cout << "🐱 ?!?!" << std::endl;
}