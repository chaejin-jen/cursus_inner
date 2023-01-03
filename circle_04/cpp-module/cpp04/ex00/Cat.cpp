#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "\033[0;90mDefault constructor called - Cat\033[0m" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other.getType()){
	std::cout << "\033[0;90mCopy constructor called - Cat\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "\033[0;90mCopy assignment operator called - Cat\033[0m" << std::endl;
	this->_type = other.getType();
	return *this;
}

Cat::~Cat(void){
	std::cout << "\033[0;90mDestructor called - Cat\033[0m" << std::endl;
}

std::string const & Cat::getType(void) const{
	return Animal::_type;
}

void Cat::makeSound(void) const{
	std::cout << "🐱 meow!" << std::endl;
}