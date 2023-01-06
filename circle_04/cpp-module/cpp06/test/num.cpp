#include <iostream>
#include <sstream>
#include <cmath>

int main(int argc, char *argv[]){
	if (argc != 2){ //|| *argv[1] == 0){
		std::cerr << "error : arguments\n[hint] ./convert <literal>" << std::endl;
		return 1;
	}

	std::string _literal(argv[1]);
	{
		if (_literal.at(_literal.length() - 1) == 'f')
			_literal = _literal.substr(0, _literal.length() - 1);
		std::cout << _literal << std::endl;
	}

	{
		double d = std::strtod(_literal.c_str(), NULL);
		//unsigned char a(d);
		std::cout << d << std::endl;
	}

	return 0;
}

/*

bool NumType::_isNumericLiteral(std::string literal){
	bool has_dot(false);
	bool has_exp(false);

	if (literal.length() == 1 && std::isdigit(literal[0]) == 0)
		return false;
	for (std::string::iterator it = literal.begin(); it != literal.end(); it++){
		if (std::isdigit(*it) == 0) {
			if (*it == '.' && has_dot == false)
				has_dot = true;
			//else if (*it == 'E' && has_exp == false)
			//	has_dot = true;
			//else if (*it == '+' && *(it - 1) == 'E' && has_exp == true)
			else
				return false;
		}
	}
	return true;
}

*/
