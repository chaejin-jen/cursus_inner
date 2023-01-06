#include "Convert.hpp"
#include <cmath>
#include <cstdlib>

Convert::Convert(void) {
}

Convert::Convert(const std::string& literal) : _literal(literal){
	
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

/* only the decimal notation will be used */
/* If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is impossible. */
void Convert::putChar(void){
	std::stringstream _ss(_literal);
	unsigned int a;

	_ss >> a;

	std::cout << "char: ";
	try{
		if (_ss.fail() || a > 255 || a < 0)
			throw Convert::SSFailException();
		if (std::isprint(a) == 0)
			throw Convert::NotDisplayableException();
		std::cout << '\'' << static_cast<unsigned char>(a) << '\'' << std::endl;
	}catch(const std::exception &e){
			std::cout << e.what();
	}
}

void Convert::putInt(void){
	std::stringstream _ss(_literal);
	int a;

	_ss >> a;
	std::cout << "int: ";
	try{
		if (_ss.fail())
			throw Convert::SSFailException();
		std::cout << a << std::endl;
	}catch(const std::exception &e){
			std::cout << e.what();
	}
	//std::cout << "(atoi: " << std::atoi(_literal.c_str()) << ')' << std::endl;
}

void Convert::putFloat(void){
	std::stringstream _ss(_literal);
	float a;

	_ss >> a;
	a = static_cast<float>(std::strtod(_literal.c_str(), NULL));
	std::cout << "float: ";
	try{
		if (_ss.fail() && a == 0)
			throw Convert::SSFailException();
		if (a == static_cast<int>(a))
			std::cout << a << ".0f" << std::endl;
		else
			std::cout << a << "f" << std::endl;
	}catch(const std::exception &e){
			std::cout << e.what();
	}
	//std::cout << "_ss.fail: " << _ss.fail() << a << std::endl;
	//std::cout << "isnan : " << std::isnan(a) << a << std::endl;
	//std::cout << "isinf : " << std::isinf(a) << a << std::endl  << std::endl;
}

void Convert::putDouble(void){
	std::stringstream _ss(_literal);
	double a;

	_ss >> a;
	a = std::strtod(_literal.c_str(), NULL);
	std::cout << "double: ";
	try{
		if (_ss.fail() && a == 0)
			throw Convert::SSFailException();
		else if (a == static_cast<int>(a))
			std::cout << a << ".0" << std::endl;
		else
			std::cout << a << std::endl;
	}catch(const std::exception &e){
			std::cout << e.what();
	}

}


const char* Convert::NotDisplayableException::what(void) const throw(){
	return "Not Displayable\n";
}

const char* Convert::SSFailException::what(void) const throw(){
	return "impossible\n";
}
