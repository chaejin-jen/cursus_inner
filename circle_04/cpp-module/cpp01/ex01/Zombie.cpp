#include "Zombie.hpp"

Zombie::Zombie( void ): _name("default"){
	std::cout << "\033[0;90m" << _name << " is born!\033[0m" << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name) {
	std::cout << "\033[0;90m" << _name << " is born!\033[0m" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << "\033[0;90m" << _name << " died!\033[0m" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string name)
{
	this->_name = name;
}
