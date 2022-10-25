#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
	std::cout << _name << " is born!" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << _name << " died!" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
