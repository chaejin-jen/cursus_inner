#pragma once
#ifndef __AFORM_H__
#define __AFORM_H__

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

// ************************************************************************** //
//                               AFORM Class                                //
// ************************************************************************** //

class AForm {
public:
	AForm(void);
	AForm(const std::string name);
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm(void);
	
	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;

	void setIsSigned(void);
	
	virtual void beSigned(Bureaucrat &br) = 0;
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class ExecuteFailException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	
private:
	const std::string _name;
	bool _isSigned;
	const int _sign;
	const int _exec;
};

std::ostream &operator<<(std::ostream &os, const AForm &data);

#endif /* __AFORM_H__ */
