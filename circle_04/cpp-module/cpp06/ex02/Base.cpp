#include "Base.hpp"
#include <iostream>

Base::~Base(void){
	std::cout << "\033[0;90mBase virtual destructor called\033[0m" << std::endl;
}
