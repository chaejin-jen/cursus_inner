#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	Fixed	e(7.625f);
	Fixed	f(-7.625f);
	Fixed	const g(-42.42f);
	Fixed	const h(0.0f);
	const Fixed i(65536.234f);
	const Fixed i_ng(-65536.234f);
	const Fixed j(65536.634f);
	const Fixed j_ng(-65536.634f);
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "h is " << h << std::endl;
	std::cout << "i is " << i << std::endl;
	std::cout << "j is " << j << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	std::cout << "g is " << g.toInt() << " as integer" << std::endl;
	std::cout << "h is " << h.toInt() << " as integer" << std::endl;
	std::cout << "i is " << i.toInt() << " as integer" << std::endl;
	std::cout << "i_ng is " << i_ng.toInt() << " as integer" << std::endl;
	std::cout << "j is " << j.toInt() << " as integer" << std::endl;
	std::cout << "j_ng is " << j_ng.toInt() << " as integer" << std::endl;
	return 0;
}
