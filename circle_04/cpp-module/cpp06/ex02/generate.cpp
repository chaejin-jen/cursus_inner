#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void){
	std::srand(std::time(NULL));
	int random(std::rand());
	if (random % 2 == 0)
		return(new A());
	else if (random % 3 == 0)
		return(new B());
	return(new C());
}
