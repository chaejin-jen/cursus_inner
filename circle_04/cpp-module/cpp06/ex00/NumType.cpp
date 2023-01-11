#include "NumType.hpp"
#include <cmath>
#include <cstdlib>
#include <climits>

NumType::NumType(void) : _type(numtype::NA){
}

NumType::NumType(const NumType& other) {
	_type = other._type;
}

NumType::~NumType(void) {
}

NumType& NumType::operator=(const NumType& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

int NumType::getType(void) const{
	return _type;
}

void NumType::setTpye(std::string literal){
	double d;
	char *back;

	/* remove 'f' (when its end of string) */
	if (literal.at(literal.length() - 1) == 'f')
		literal = literal.substr(0, literal.length() - 1);

	/* str : 123.45abc -> d: 123.45, back: str + 6, *back: 'a' */
	d = std::strtod(literal.c_str(), &back);
	if (*back){
		_type = numtype::NA;
		return ;
	}

	if (d >= (CHAR_MAX - CHAR_MAX) && d <= UCHAR_MAX)
		_type = numtype::UCHAR_TYPE;
	else if (d >= INT_MIN && d <= INT_MAX)
		_type = numtype::INT_TYPE;
	else
		_type = numtype::FLOAT_TYPE;
}
