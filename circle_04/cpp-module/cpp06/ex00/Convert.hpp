#pragma once
#ifndef __CONVERT_H__
#define __CONVERT_H__

#include <iostream>
#include <exception>
#include <sstream>

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
	class SSFailException : public std::exception{
	public:
		const char* what(void) const throw();
	};
private:
	std::string _literal;

	Convert(void);
};

#endif /* __CONVERT_H__ */
