#include "AMateria.hpp"

AMateria::AMateria(void) : _type("_"){
	std::cout << "\033[0;90mDefault constructor called - AMateria\033[0m" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type){
	std::cout << "\033[0;90mConstructor called (std::string) - AMateria\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria& other){
	std::cout << "\033[0;90mCopy constructor called - AMateria\033[0m" << std::endl;
	_type = other.getType();
}

AMateria& AMateria::operator=(const AMateria& other){
	std::cout << "\033[0;90mCopy assignment operator called - AMateria\033[0m" << std::endl;
	_type = other.getType();
	return *this;
}

AMateria::~AMateria(void){
	std::cout << "\033[0;90mDestructor called - AMateria\033[0m" << std::endl;
}

std::string const & AMateria::getType() const{
	return _type;
}; //Returns the materia type

void AMateria::use(ICharacter& target){
	std::cout << "* " << target << " *" << std::endl;
}

