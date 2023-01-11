#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("unnamed", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: AForm(name, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), 25, 5){}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

void PresidentialPardonForm::beSigned(Bureaucrat &br){
	if (br.getGrade() > getGradeToSign()) {
		throw PresidentialPardonForm::GradeTooLowException();
	} else {
		setIsSigned();
	}
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > getGradeToExecute()){
		throw GradeTooLowException();
	} else {
		std::cout << executor.getName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &data){
	os << data.getName() << ". PresidentialPardonForm signed " 
		<< (data.getIsSigned() ? "TRUE" : "FALSE")
		<< ", grade to sign " << data.getGradeToSign()
		<< ", grade to execute " << data.getGradeToExecute();
	return os;
}
