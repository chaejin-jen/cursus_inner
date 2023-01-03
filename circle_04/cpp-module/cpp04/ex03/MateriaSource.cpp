#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
	std::cout << "\033[0;90mDefault constructor called - MateriaSource\033[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other){
	std::cout << "\033[0;90mCopy constructor called - MateriaSource\033[0m" << std::endl;
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	std::cout << "\033[0;90mCopy assignment operator called - MateriaSource\033[0m" << std::endl;
	*this = other;
	return *this;
}

MateriaSource::~MateriaSource(void){
	std::cout << "\033[0;90mDestructor called - MateriaSource\033[0m" << std::endl;
}

void MateriaSource::learnMateria(AMateria* T){
	std::cout << "\033[0;94mlearn Materia : " << T->getType() << "\033[0m" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	std::cout << "\033[0;94mcreate Materia : " << type << "\033[0m" << std::endl;

}