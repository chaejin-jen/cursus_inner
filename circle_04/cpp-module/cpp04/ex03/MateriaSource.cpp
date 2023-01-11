#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void) : _type("_"){
	//std::cout << "\033[0;90mDefault constructor called - MateriaSource\033[0m" << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other){
	//std::cout << "\033[0;90mCopy constructor called - MateriaSource\033[0m" << std::endl;
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	//std::cout << "\033[0;90mCopy assignment operator called - MateriaSource\033[0m" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	for (int i = 0 ; i < 4 ; i++){
		if (other._materia[i] != NULL){
			if (_materia[i] != NULL)
				delete _materia[i];
			_materia[i] = other._materia[i]->clone();
		}
		else
			_materia[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource(void){
	//std::cout << "\033[0;90mDestructor called - MateriaSource\033[0m" << std::endl;
	for (int i = 0 ; i < 4 ; i++){
		if (_materia[i])
			delete _materia[i];
	}
}

void MateriaSource::learnMateria(AMateria* T){
	////std::cout << "\033[0;94mlearn Materia : " << T->getType() << "\033[0m" << std::endl;
	if (T == NULL)
		return ;
	int i(-1);
	while (++i < 4 && _materia[i])
		;
	if (i >= 4){
		//std::cout << "\033[0;MateriaSource is full.\033[0m" << std::endl;
		return ;
	}
	_materia[i] = T->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type){
	////std::cout << "\033[0;94mcreate Materia : " << type << "\033[0m" << std::endl;
	AMateria *aMateria;
	if (type == "ice")
		aMateria = new Ice(type);
	else if (type == "cure")
		aMateria = new Cure(type);
	else
		aMateria = 0; // AMateria(std::string const & type) 생성자에서 segfault 걸림 (근데 과제에 명시 되어있음)
	return aMateria;
}