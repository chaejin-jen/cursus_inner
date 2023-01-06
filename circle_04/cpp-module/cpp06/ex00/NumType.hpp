#pragma once
#ifndef __NUMTYPE_H__
#define __NUMTYPE_H__

#include <iostream>
#include <exception>
#include <sstream>

namespace numtype{
	typedef enum e_type{
		NA,
		UCHAR_TYPE,
		INT_TYPE,
		FLOAT_TYPE,
	}t_type;
}

// ************************************************************************** //
//                               NUMTYPE Class                                //
// ************************************************************************** //

class NumType {
public:
	NumType(void);
	NumType(const NumType& other);
	NumType& operator=(const NumType& other);
	~NumType(void);

	int getType(void) const;
	void setTpye(std::string literal);

private:
	int _type;

	bool _isNumericLiteral(std::string literal);
};

#endif /* __NUMTYPE_H__ */
