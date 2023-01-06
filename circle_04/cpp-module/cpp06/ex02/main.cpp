#include "Base.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void) {
	Base* base;

	base = generate();
	identify(base);
	identify(*base);
	return (0);
}
