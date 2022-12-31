#include "Fixed.hpp"

const int Fixed::_nbits = 8;

Fixed::Fixed(void) : _raw(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _raw(n << Fixed::_nbits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;

	const int	*p; // int	*p = (int *)(&f);
	p = static_cast<const int *>(static_cast<const void *>(&f));

	int(exp) = ((*p & fixed::float_exp_bits_mask) >> 23) - 127;
	if (f == 0 || exp <= -fixed::float_frac_nbits){			/* zero or too small */
		this->_raw = 0;
		return ;
	}
	if (exp >= fixed::float_frac_nbits)
		std::cerr << "\033[0;31m[warning] out of range : "
			<< f << "\033[0m" << std::endl;

	int	fixed_int_nbits(fixed::float_frac_nbits - Fixed::_nbits);
	this->_raw = *p & fixed::float_frac_bits_mask;
	if (exp < fixed_int_nbits){
		this->_raw += 1 << (fixed_int_nbits - (exp + 1));
		this->_raw = this->_raw >> (fixed_int_nbits - exp);
	}
	else{
		this->_raw = this->_raw << (exp - fixed_int_nbits);
	}
	if (exp + Fixed::_nbits >= 0)
		this->_raw += (1 << (exp + Fixed::_nbits));
	if (*p & fixed::sign_bit)
		this->_raw = ~this->_raw + 1;
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

float Fixed::toFloat(void) const {
	// std::cout << "static_cast<float>(this->_raw) : "
	// 	<< static_cast<float>(this->_raw) << std::endl;
	// std::cout << "1 << Fixed::_nbits : "
	// 	<< (1 << Fixed::_nbits) << std::endl;
	return static_cast<float>(this->_raw) / (1 << Fixed::_nbits);
}

int Fixed::toInt(void) const {
	return this->_raw >> Fixed::_nbits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}