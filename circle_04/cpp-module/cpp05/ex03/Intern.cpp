#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void){}

Intern::Intern(const Intern& other){
	*this = other;
}

Intern::~Intern(void) {
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

AForm* Intern::makeForm(std::string form_name, std::string b_name) const{
	
	std::string fname[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	AForm* (*FncPtr[3])(std::string name) = {
		&Intern::_makeShrubberyCreationForm,
		&Intern::_makeRobotomyRequestForm,
		&Intern::_makePresidentialPardonForm
	};

	int i(-1);
	while (++i < 3 && form_name != fname[i]) ;

	if (i < 3)
		return (FncPtr[i](b_name));
	throw NonExistentForm();
	return NULL;
}

AForm* Intern::_makeShrubberyCreationForm( std::string name ){
	return (new ShrubberyCreationForm(name));
}

AForm* Intern::_makeRobotomyRequestForm( std::string name ){
	return (new RobotomyRequestForm(name));
}

AForm* Intern::_makePresidentialPardonForm( std::string name ){
	return (new PresidentialPardonForm(name));
}

const char *Intern::NonExistentForm::what(void) const throw(){
	return "non-existent form!";
}