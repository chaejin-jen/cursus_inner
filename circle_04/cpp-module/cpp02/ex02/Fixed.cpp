#include "Fixed.hpp"
#include <cmath>

const int Fixed::_nbits = 8;

Fixed::Fixed(void) : _raw(0){
	// std::cout << "\033[0;90mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const int n) : _raw(n << Fixed::_nbits){
	// std::cout << "\033[0;90mInt constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const float f) {
	// std::cout << "\033[0;90mFloat constructor called\033[0m" << std::endl;

	// const int	*p; // int	*p = (int *)(&f);
	// p = static_cast<const int *>(static_cast<const void *>(&f));

	// int(exp) = ((*p & fixed::float_exp_bits_mask) >> 23) - 127;
	// if (f == 0 || exp <= -fixed::float_frac_nbits){			/* zero or too small scale */
	// 	this->_raw = 0;
	// 	return ;
	// }
	// if (exp >= fixed::float_frac_nbits)
	// 	std::cerr << "\033[0;31m[warning] out of range : "	/* too small or too big */
	// 		<< f << "\033[0m" << std::endl;
	this->_raw = static_cast<int>(roundf(f * (1 << Fixed::_nbits)));
}

Fixed::Fixed(const Fixed& other) {
	// std::cout << "\033[0;90mCopy constructor called\033[0m" << std::endl;
	this->setRawBits(other.getRawBits()); // *this = other;
}

Fixed::~Fixed(void) {
	// std::cout << "\033[0;90mDestructor called\033[0m" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "\033[0;90mCopy assignment operator called\033[0m" << std::endl;
	if (this != &other) {
		this->setRawBits(other.getRawBits());
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	// std::cout << "\033[0;90mgetRawBits member function called\033[0m" << std::endl;
	return this->_raw;
}
void Fixed::setRawBits(int const raw) {
	this->_raw = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_raw) / (1 << Fixed::_nbits);
}

int Fixed::toInt(void) const {
	return this->_raw >> Fixed::_nbits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& other) const{
	return this->_raw > other._raw ? true : false;
}
bool Fixed::operator<(const Fixed& other) const{
	return this->_raw < other._raw ? true : false;
}
bool Fixed::operator>=(const Fixed& other) const{
	return this->_raw >= other._raw ? true : false;
}
bool Fixed::operator<=(const Fixed& other) const{
	return this->_raw <= other._raw ? true : false;
}
bool Fixed::operator==(const Fixed& other) const{
	return this->_raw == other._raw ? true : false;
}
bool Fixed::operator!=(const Fixed& other) const{
	return this->_raw != other._raw ? true : false;
}

Fixed& Fixed::operator+=(const Fixed& other){
	this->_raw += other._raw;
	return *this;
}

Fixed Fixed::operator+(const Fixed& other) const{
	Fixed tmp;

	tmp._raw = this->_raw + other._raw;
	return tmp;
}

Fixed& Fixed::operator-=(const Fixed& other){
	this->_raw -= other._raw;
	return *this;
}

Fixed Fixed::operator-(const Fixed& other) const{
	Fixed tmp;

	tmp._raw = this->_raw - other._raw;
	return tmp;
}

Fixed& Fixed::operator*=(const Fixed& other){
	*this = this->toFloat() * other.toFloat();
	return *this;
}

Fixed Fixed::operator*(const Fixed& other) const{
	Fixed tmp(this->toFloat() * other.toFloat());
	return tmp;
	
}

Fixed& Fixed::operator/=(const Fixed& other){
	if (other._raw == 0){
		std::cerr << "\033[0;31m[error] zero divide\033[0m" << std::endl;
		exit(1);
	}
	*this = this->toFloat() / other.toFloat();
	return *this;
}

Fixed Fixed::operator/(const Fixed& other) const{
	if (other._raw == 0){
		std::cerr << "\033[0;31m[error] zero divide\033[0m" << std::endl;
		exit(1);
	}
	Fixed tmp(this->toFloat() / other.toFloat());
	return tmp;
}

Fixed& Fixed::operator++(void){
	this->_raw += 1;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed	tmp(*this);

	this->_raw += 1;
	return tmp;
}

Fixed& Fixed::operator--(void){
	this->_raw -= 1;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed	tmp(*this);

	this->_raw -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	return a._raw < b._raw ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return a._raw < b._raw ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return a._raw > b._raw ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return a._raw > b._raw ? a : b;
}