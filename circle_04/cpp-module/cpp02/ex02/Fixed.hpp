#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

namespace fixed{
	/* float bit layout (32 bits) : seee eeee emmm mmmm mmmm mmmm mmmm mmmm */
	const int float_frac_nbits = 23;
	const int float_exp_bits_mask = 0b11111111 << float_frac_nbits;
	const int float_frac_bits_mask = 0b11111111111111111111111;
	const int sign_bit = 1 << 31;
}

// ************************************************************************** //
//                               FIXED Class                                //
// ************************************************************************** //

class Fixed {
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		
		Fixed& operator+=(const Fixed& other);
		Fixed operator+(const Fixed& other) const;
		Fixed& operator-=(const Fixed& other);
		Fixed operator-(const Fixed& other) const;
		Fixed& operator*=(const Fixed& other);
		Fixed operator*(const Fixed& other) const;
		Fixed& operator/=(const Fixed& other);
		Fixed operator/(const Fixed& other) const;
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
		
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int _raw;
		static const int _nbits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);

#endif /* __FIXED_H__ */
