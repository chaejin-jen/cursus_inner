#include "Animal.hpp"

Animal::Animal(void) : _type("_"){
	std::cout << "\033[0;90mDefault constructor called - Animal\033[0m" << std::endl;
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "\033[0;90mConstructor called (std::string) - Animal\033[0m" << std::endl;
}

Animal::Animal(const Animal& other){
	std::cout << "\033[0;90mCopy constructor called - Animal\033[0m" << std::endl;
	_type = other.getType();
}

Animal& Animal::operator=(const Animal& other){
	std::cout << "\033[0;90mCopy assignment operator called - Animal\033[0m" << std::endl;
	_type = other.getType();
	return *this;
}

Animal::~Animal(void){
	std::cout << "\033[0;90mDestructor called - Animal\033[0m" << std::endl;
}

std::string const & Animal::getType(void) const{
	return _type;
}

void Animal::makeSound(void) const{
	std::cout << "??? @#*&#*~" << std::endl;
}