#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << "\033[0;90mDefault constructor called - Dog\033[0m" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other.getType()){
	std::cout << "\033[0;90mCopy constructor called - Dog\033[0m" << std::endl;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other){
	std::cout << "\033[0;90mCopy assignment operator called - Dog\033[0m" << std::endl;
	type = other.getType();
	brain = new Brain(*other.brain);
	return *this;
}

Dog::~Dog(void){
	std::cout << "\033[0;90mDestructor called - Dog\033[0m" << std::endl;
	delete brain;
}

std::string const & Dog::getType(void) const{
	return type;
}

void Dog::makeSound(void) const{
	std::cout << "🐶 bark!" << std::endl;
}

void Dog::seeBrain(void) const{
	brain->putIdeas();
}

void Dog::copyBrain(Brain &other){
	*brain = other;
}
