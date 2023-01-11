#include "Ice.hpp"

Ice::Ice(void) {
	//std::cout << "\033[0;90mDefault constructor called - Ice\033[0m" << std::endl;
	_type = "ice";
}

Ice::Ice(std::string const & type){
	//std::cout << "\033[0;90mConstructor called (std::string) - Ice\033[0m" << std::endl;
	_type = type;
}

Ice::Ice(const Ice& other){
	//std::cout << "\033[0;90mCopy constructor called - Ice\033[0m" << std::endl;
	_type = other.getType();
}

Ice& Ice::operator=(const Ice& other){
	//std::cout << "\033[0;90mCopy assignment operator called - Ice\033[0m" << std::endl;
	_type = other.getType();
	return *this;
}

Ice::~Ice(void){
	//std::cout << "\033[0;90mDestructor called - Ice\033[0m" << std::endl;
}

Ice* Ice::clone() const{
	return new Ice();
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
