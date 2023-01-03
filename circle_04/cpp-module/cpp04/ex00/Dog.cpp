#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << "\033[0;90mDefault constructor called - Dog\033[0m" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other.getType()){
	std::cout << "\033[0;90mCopy constructor called - Dog\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
	std::cout << "\033[0;90mCopy assignment operator called - Dog\033[0m" << std::endl;
	this->_type = other.getType();
	return *this;
}

Dog::~Dog(void){
	std::cout << "\033[0;90mDestructor called - Dog\033[0m" << std::endl;
}

std::string const & Dog::getType(void) const{
	return Animal::_type;
}

void Dog::makeSound(void) const{
	std::cout << "🐶 bark!" << std::endl;
}