#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p){
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &) {}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &) {}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &) {}
}
