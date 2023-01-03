#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("_"){
	std::cout << "\033[0;90mDefault constructor called - WrongAnimal\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "\033[0;90mConstructor called (std::string) - WrongAnimal\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	std::cout << "\033[0;90mCopy constructor called - WrongAnimal\033[0m" << std::endl;
	_type = other.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	std::cout << "\033[0;90mCopy assignment operator called - WrongAnimal\033[0m" << std::endl;
	_type = other.getType();
	return *this;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "\033[0;90mDestructor called - WrongAnimal\033[0m" << std::endl;
}

std::string const & WrongAnimal::getType(void) const{
	return _type;
}

void WrongAnimal::makeSound(void) const{
	std::cout << "??? WRONG@#*&#*~" << std::endl;
}