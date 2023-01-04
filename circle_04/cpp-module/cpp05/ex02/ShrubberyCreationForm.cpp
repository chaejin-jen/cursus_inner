#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("unnamed", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: AForm(name, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), 145, 137){}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

void ShrubberyCreationForm::beSigned(Bureaucrat &br){
	if (br.getGrade() > getGradeToSign()) {
		throw ShrubberyCreationForm::GradeTooLowException();
	} else {
		setIsSigned();
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > getGradeToExecute()){
		throw GradeTooLowException();
	} else {
		std::ofstream	ofs;
		ofs.open(std::string(executor.getName()) + "_shrubbery", std::ios::out | std::ios::trunc);
		if (ofs.is_open() == false)
			throw ExecuteFailException();
		ofs << "		&&& &&  & &&\n"
			<< "	&& &\\/&\\|& ()|/ @, &&\n"
			<< "	&\\/(/&/&||/& /_/)_&/_&\n"
			<< "&() &\\/&|()|/&\\/ '%\" & ()\n"
			<< "&_\\_&&_\\ |& |&&/&__%_/_& &&\n"
			<< "&&   && & &| &| /& & % ()& /&&\n"
			<< "()&_---()&\\&\\|&&-&&--%---()~\n"
			<< "	&&     \\|||\n"
			<< "			|||\n"
			<< "			|||\n"
			<< "			|||\n"
			<< "	, -=-~  .-^- _\n"
			<< "ejm97         `";
		if (ofs.fail())
			throw ExecuteFailException();
		ofs.close();
	}
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &data){
	os << data.getName() << ". ShrubberyCreationForm signed " 
		<< (data.getIsSigned() ? "TRUE" : "FALSE")
		<< ", grade to sign " << data.getGradeToSign()
		<< ", grade to execute " << data.getGradeToExecute();
	return os;
}
