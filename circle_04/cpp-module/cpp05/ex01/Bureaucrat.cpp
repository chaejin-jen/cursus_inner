#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("unnamed"), _grade(150){
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

std::string Bureaucrat::getName(void) const{
	return _name;
}

int Bureaucrat::getGrade(void) const{
	return _grade;
}

void Bureaucrat::setGrade(int grade){
	if (grade < bureaucrat::MIN)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > bureaucrat::MAX)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

void Bureaucrat::incGrade(void){
	setGrade(_grade - 1);
}

void Bureaucrat::decGrade(void){
	setGrade(_grade + 1);
}

void Bureaucrat::signForm(Form &form){
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << *this << " couldn’t sign " << form << " because "
			<< e.what() << std::endl;
	}
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw(){
	return "grade too high!";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw(){
	return "grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data){
	os << data.getName() << ", bureaucrat grade " << data.getGrade();
	return os;
}
