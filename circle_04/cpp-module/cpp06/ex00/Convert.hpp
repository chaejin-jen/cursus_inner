#pragma once
#ifndef __CONVERT_H__
#define __CONVERT_H__

#include <iostream>
#include <exception>
#include <sstream>

#include "NumType.hpp"

// ************************************************************************** //
//                               CONVERT Class                                //
// ************************************************************************** //

class Convert {
public:
	Convert(const std::string& literal);
	Convert(const Convert& other);
	Convert& operator=(const Convert& other);
	~Convert(void);

	void putChar(void);
	void putInt(void);
	void putFloat(void);
	void putDouble(void);

	class NotDisplayableException : public std::exception{
	public:
		const char* what(void) const throw();
	};
	class ImpossibleException : public std::exception{
	public:
		const char* what(void) const throw();
	};
private:
	std::string _literal;
	double _d;
	NumType _type;

	Convert(void);
	static int _detectType(std::string literal);
};

#endif /* __CONVERT_H__ */
