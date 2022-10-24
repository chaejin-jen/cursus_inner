#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("unknown") { }
Zombie::Zombie( std::string name ) : _name(name) { }
Zombie::~Zombie( void ) {
	std::cout << _name << " is completely dead!" << std::endl;
}
void Zombie::announce(void) const
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
