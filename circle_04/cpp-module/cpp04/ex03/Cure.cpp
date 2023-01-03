#include "Cure.hpp"

Cure::Cure(void) : type("Cure"){
	std::cout << "\033[0;90mDefault constructor called - Cure\033[0m" << std::endl;
}

Cure::Cure(std::string const & type) : type(type){
	std::cout << "\033[0;90mConstructor called (std::string) - Cure\033[0m" << std::endl;
}

Cure::Cure(const Cure& other){
	std::cout << "\033[0;90mCopy constructor called - Cure\033[0m" << std::endl;
	type = other.getType();
}

Cure& Cure::operator=(const Cure& other){
	std::cout << "\033[0;90mCopy assignment operator called - Cure\033[0m" << std::endl;
	type = other.getType();
	return *this;
}

Cure::~Cure(void){
	std::cout << "\033[0;90mDestructor called - Cure\033[0m" << std::endl;
}

AMateria* Cure::clone(){
	return new Cure();
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName()
		<< "’s wounds *" << std::endl;
}
