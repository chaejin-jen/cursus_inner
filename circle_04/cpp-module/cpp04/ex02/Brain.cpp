#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "\033[0;90mDefault constructor called - Brain\033[0m" << std::endl;
	_empty_brain();
}

Brain::Brain(const Brain &other) {
	std::cout << "\033[0;90mConstructor called (std::string) - Brain\033[0m" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other){
	std::cout << "\033[0;90mCopy assignment operator called - Brain\033[0m" << std::endl;
	if (this != &other){
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain(void){
	std::cout << "\033[0;90mDestructor called - Brain\033[0m" << std::endl;
}

void Brain::putIdeas(void) const{
	for (int i = 0; i < 100; i++)
		std::cout << i << " : " << ideas[i] << std::endl;
}

void Brain::_empty_brain(void){
	for (int i = 0; i < 100; i++)
		ideas[i] = "(null)";
}

void Brain::setIdea(std::string idea, int idx) {
	if (idx >= 0 && idx < 100) 
		ideas[idx] = idea;
}