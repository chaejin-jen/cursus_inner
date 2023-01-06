#include "Convert.hpp"
#include <cmath>
#include <cstdlib>

Convert::Convert(void) {
}

Convert::Convert(const std::string& literal) : _literal(literal){
	_type.setTpye(_literal);
	_d = std::strtod(literal.c_str(), NULL);
}

Convert::Convert(const Convert& other) {
	_literal = other._literal;
}

Convert::~Convert(void) {
}

Convert& Convert::operator=(const Convert& other) {
	if (this != &other) {
		_literal = other._literal;
	}
	return *this;
}

void Convert::putChar(void){
	std::cout << "char: ";
	try{
		if (_type.getType() != numtype::UCHAR_TYPE)
			throw Convert::ImpossibleException();
		if (std::isprint(static_cast<unsigned char>(_d)) == 0)
			throw Convert::NotDisplayableException();
		std::cout << '\'' << static_cast<unsigned char>(_d) << '\'' << std::endl;
	}catch(const std::exception &e){
		std::cout << e.what();
	}
}

void Convert::putInt(void){
	std::cout << "int: ";
	try{
		if (_type.getType() != numtype::UCHAR_TYPE
			&& _type.getType() != numtype::INT_TYPE)
			throw Convert::ImpossibleException();
		std::cout << static_cast<int>(_d) << std::endl;
	}catch(const std::exception &e){
		std::cout << e.what();
	}
}

void Convert::putFloat(void){
	float a;

	a = static_cast<float>(_d);
	std::cout << "float: ";
	try{
		if (_type.getType() == numtype::NA)
			throw Convert::ImpossibleException();
		if (a == static_cast<int>(a))
			std::cout << a << ".0f" << std::endl;
		else
		std::cout << static_cast<float>(_d) << "f" << std::endl;
	}catch(const std::exception &e){
		std::cout << e.what();
	}
	//std::cout << "isnan : " << std::isnan(a) << a << std::endl;
	//std::cout << "isinf : " << std::isinf(a) << a << std::endl  << std::endl;
}

void Convert::putDouble(void){
	std::cout << "double: ";
	try{
		if (_type.getType() == numtype::NA)
			throw Convert::ImpossibleException();
		else if (_d == static_cast<int>(_d))
			std::cout << _d << ".0" << std::endl;
		else
			std::cout << _d << std::endl;
	}catch(const std::exception &e){
		std::cout << e.what();
	}

}

const char* Convert::NotDisplayableException::what(void) const throw(){
	return "Not Displayable\n";
}

const char* Convert::ImpossibleException::what(void) const throw(){
	return "impossible\n";
}
