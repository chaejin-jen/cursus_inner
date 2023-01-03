#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "\033[0;90mDefault constructor called - Cat\033[0m" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other.getType()){
	std::cout << "\033[0;90mCopy constructor called - Cat\033[0m" << std::endl;
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "\033[0;90mCopy assignment operator called - Cat\033[0m" << std::endl;
	type = other.getType();
	brain = new Brain(*other.brain);
	return *this;
}

Cat::~Cat(void){
	std::cout << "\033[0;90mDestructor called - Cat\033[0m" << std::endl;
	delete brain;
}

std::string const & Cat::getType(void) const{
	return Animal::type;
}

void Cat::makeSound(void) const{
	std::cout << "🐱 meow!" << std::endl;
}

void Cat::seeBrain(void) const{
	brain->putIdeas();
}

void Cat::copyBrain(Brain &other){
	*brain = other;
}