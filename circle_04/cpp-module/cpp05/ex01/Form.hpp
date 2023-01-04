#pragma once
#ifndef __FORM_H__
#define __FORM_H__

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

// ************************************************************************** //
//                               FORM Class                                //
// ************************************************************************** //

class Form {
public:
	Form(void);
	Form(std::string name);
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form(void);
	
	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	
	void beSigned(Bureaucrat &br);

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &other);
		virtual ~GradeTooHighException(void) throw();

		GradeTooHighException &operator=(const GradeTooHighException &other);

		virtual const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &other);
		virtual ~GradeTooLowException(void) throw();

		GradeTooLowException &operator=(const GradeTooLowException &other);

		virtual const char* what(void) const throw();
	};
	
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &data);

#endif /* __FORM_H__ */
