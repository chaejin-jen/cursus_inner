#include "AForm.hpp"

AForm::AForm(void)
	: _name("unnamed"), _isSigned(false), _sign(1), _exec(1){
}

AForm::AForm(const std::string name)
	: _name(name), _isSigned(false), _sign(1), _exec(1){
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name), _isSigned(false), _sign(gradeToSign), _exec(gradeToExecute){
	if (_sign < bureaucrat::MIN || _exec < bureaucrat::MIN) {
		AForm::GradeTooHighException();
	} else if (_sign > bureaucrat::MAX || _exec > bureaucrat::MAX) {
		AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& other)
	: _name(other.getName()), _isSigned(other._isSigned),
	_sign(other._sign), _exec(other._exec){
}

AForm::~AForm(void) {
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

std::string AForm::getName(void) const{
	return _name;
}

bool AForm::getIsSigned(void) const{
	return _isSigned;
}

int AForm::getGradeToSign(void) const{
	return _sign;
}

int AForm::getGradeToExecute(void) const{
	return _exec;
}

void AForm::setIsSigned(void){
	_isSigned = true;
}

const char * AForm::GradeTooHighException::what(void) const throw(){
	return "grade too high!";
}

const char * AForm::GradeTooLowException::what(void) const throw(){
	return "grade too low!";
}

const char * AForm::ExecuteFailException::what(void) const throw(){
	return "exceute failed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &data){
	os << data.getName() << ". Form signed " 
		<< (data.getIsSigned() ? "\033[0;102mTRUE\033[0m" : "\033[0;43mFALSE\033[0m")
		<< ", grade to sign " << data.getGradeToSign()
		<< ", grade to execute " << data.getGradeToExecute();
	return os;
}
