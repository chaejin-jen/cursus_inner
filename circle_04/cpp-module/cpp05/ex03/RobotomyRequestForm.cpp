#include "RobotomyRequestForm.hpp"
#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("unnamed", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm(name, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), 72, 45){}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat &br){
	if (br.getGrade() > getGradeToSign()) {
		throw GradeTooLowException();
	} else {
		setIsSigned();
	}
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > getGradeToExecute()){
		throw GradeTooLowException();
	} else {
		std::cout << getName() << " : rizzz, bzzzzzz\n";
		srand(time(NULL));
		std::cout << getName() << " : ";
		if (rand() % 2)
			std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "the robotomy failed" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &data){
	os << data.getName() << ". RobotomyRequestForm signed " 
		<< (data.getIsSigned() ? "TRUE" : "FALSE")
		<< ", grade to sign " << data.getGradeToSign()
		<< ", grade to execute " << data.getGradeToExecute();
	return os;
}
