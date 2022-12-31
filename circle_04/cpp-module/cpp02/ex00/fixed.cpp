#include "Fixed.hpp"

const int Fixed::_nbits = 8;

Fixed::Fixed(void) : _raw(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits()); // *this = other;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->setRawBits(other.getRawBits());
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}
void Fixed::setRawBits(int const raw) {
	this->_raw = raw;
}
