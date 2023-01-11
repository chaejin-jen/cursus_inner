#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

int putStringStream(std::stringstream &ss);

int main(int argc, char *argv[]){
	if (argc != 2){ //|| *argv[1] == 0){
		std::cerr << "error : arguments\n[hint] ./convert <literal>" << std::endl;
		return 1;
	}

	//{
	//	double a(1.79e+308);
	//	std::cout << "\033[0;106ma : " << a << "\033[0m" << std::endl;
	//}

	std::cout << "=== char ===" << std::endl;
	{
		//std::stringstream _ss(argv[1]);
		//unsigned int a;

		//_ss >> a;
		//std::cout << "\033[0;96mgood " << static_cast<char>(a) << "\033[0m" << std::endl;
		unsigned char a(std::atoi(argv[1]));
		//unsigned char a(-1);
		if (a == 255)
			std::cout << "a == 255" << std::endl;
		std::cout << "char : " << a << std::endl  << std::endl;
	}

	std::cout << "=== int ===" << std::endl;
	{
		std::stringstream _ss(argv[1]);
		int a;

		_ss >> a;
		std::cout << "\033[0;96mgood " << a << "\033[0m" << std::endl;
	}

	std::cout << "=== float ===" << std::endl;
	{
		//std::stringstream _ss(argv[1]);
		//float a;

		//_ss >> a;
		//if (!putStringStream(_ss))
		//	std::cout << "\033[0;96mgood " << a << "\033[0m" << std::endl;
		//if (std::isnan(a))
		//	std::cout << "\033[0;107ma : " << a << "\033[0m" << std::endl;
		//if (std::isinf(a))
		//	std::cout << "\033[0;108ma : " << a << "\033[0m" << std::endl;
		float a(std::strtod(argv[1], 0));
		std::cout << "\033[0;108ma : " << a << "\033[0m" << std::endl;
		std::cout << "isnan : " << std::isnan(a) << a << std::endl;
		std::cout << "isinf : " << std::isinf(a) << a << std::endl  << std::endl;
	}

	std::cout << "=== double ===" << std::endl;
	{
		std::stringstream _ss(argv[1]);
		double a;

		_ss >> a;
		std::cout << "\033[0;96mgood " << a << "\033[0m" << std::endl;
		if (std::isnan(a))
			std::cout << "\033[0;107ma : " << a << "\033[0m" << std::endl;
		if (std::isinf(a))
			std::cout << "\033[0;108ma : " << a << "\033[0m" << std::endl;
	}

	return 0;
}
