#include "Form.hpp"

Form::Form(void) : _name("unnamed"), _isSigned(false), _gradeToSign(0), _gradeToExecute(0){
}

Form::Form(std::string name) : _name(name), _isSigned(false), _gradeToSign(0), _gradeToExecute(0){
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (_gradeToSign < bureaucrat::MIN || _gradeToExecute < bureaucrat::MIN) {
		Form::GradeTooHighException();
	} else if (_gradeToSign > bureaucrat::MAX || _gradeToExecute > bureaucrat::MAX) {
		Form::GradeTooLowException();
	}
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
}

Form::~Form(void) {
}

Form& Form::operator=(const Form& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

std::string Form::getName(void) const{
	return _name;
}

bool Form::getIsSigned(void) const{
	return _isSigned;
}

int Form::getGradeToSign(void) const{
	return _gradeToSign;
}

int Form::getGradeToExecute(void) const{
	return _gradeToExecute;
}


void Form::beSigned(Bureaucrat &br){
	if (br.getGrade() > _gradeToSign) {
		throw Form::GradeTooLowException();
	} else {
		_isSigned = true;
	}
}


Form::GradeTooHighException::GradeTooHighException(void){}
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &copy){
	*this = copy;
}
Form::GradeTooHighException::~GradeTooHighException(void) throw(){}
Form::GradeTooHighException 
	&Form::GradeTooHighException::operator=(GradeTooHighException const &other) {
	if (this != &other) {
		*this = other;
	}
	return *this;
}
const char * Form::GradeTooHighException::what(void) const throw(){
	return "grade too high to sign this form!";
}

Form::GradeTooLowException::GradeTooLowException(void){}
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &copy){
	*this = copy;
}
Form::GradeTooLowException::~GradeTooLowException(void) throw(){}
Form::GradeTooLowException 
	&Form::GradeTooLowException::operator=(GradeTooLowException const &other) {
	if (this != &other) {
		*this = other;
	}
	return *this;
}
const char * Form::GradeTooLowException::what(void) const throw(){
	return "grade too low to sign this form!";
}

std::ostream &operator<<(std::ostream &os, const Form &data){
	os << data.getName() << ". Form signed " 
		<< (data.getIsSigned() ? "TRUE" : "FALSE")
		<< ", grade to sign " << data.getGradeToSign()
		<< ", grade to execute " << data.getGradeToSign();
	return os;
}
