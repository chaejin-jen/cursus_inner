#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

// ************************************************************************** //
//                               FIXED Class                                //
// ************************************************************************** //

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		// static void getNBits();
	private:
		int _raw;
		static const int _nbits;
};

#endif /* __FIXED_H__ */
