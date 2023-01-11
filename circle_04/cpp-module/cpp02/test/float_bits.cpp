#include <iostream>

namespace fixed{
	// const int exp_bits_mask_s = 0x000000FF;
	const int exp_bits_mask = 0x7F800000; //2139095040
	const int frac_bits_mask = 0x007FFFF0; //8388592
	const int sign_bit = 0x80000000;
	const int none_frac_nbits = 9;
	const int exp_nbits = 8;
	const int frac_nbits = 23;
}

int	main()
{
	// float data(1230.1234);
	// float data(263.3);
	// float data(1234.4321f);
	float	data(0.00625f);
	// float	data(0.625f);
	// float	data(7.625f);
	// float	data(-7.625f);
	// float	const data(-42.42f);
	// float	const data(0.0f);
	// const float data(65536.234f);
	// const float data(-65536.234f);
	std::cout << data << std::endl;
	
	/* size */
	// std::cout << sizeof(float) << std::endl;
	// std::cout << sizeof(int) << std::endl;

	

	/* float를 int로 바꾸면 소수점 버림됨 -> p 필요*/
	// std::cout << (static_cast<int>(data) & 0x7F800000) << std::endl;
	// std::cout << (static_cast<int>(data) & 0x007FFFF0) << std::endl;
	// std::cout << "exp : "<< static_cast<int>(data) & exp_bits_mask << std::endl;
	// std::cout << "frac_bits : " << static_cast<int>(data) & frac_bits_mask; << std::endl;
	// std::cout << "============" << std::endl;
	
	/* exp bits, frac bits */
	int *p = (int *)(&data);
	// std::cout << (*p & 0x7F8000) << std::endl;
	// std::cout << (*p & 0x7FFFF0) << std::endl;
	
	/* 지수와 fraction 구하기 */
	int exp(((*p & fixed::exp_bits_mask) >> 23) - 127);
	int frac_bits(*p & fixed::frac_bits_mask);
	std::cout << exp << std::endl;
	std::cout << frac_bits << std::endl;

	/* 정수부 구하기 */
	if (exp < 0)
		std::cout << "int : " << (frac_bits >> (23 - exp)) + (1 >> exp) << std::endl;
	else
		std::cout << "int : " << (frac_bits >> (23 - exp)) + (1 << exp) << std::endl;

	// /* 정수부 구하기 */
	// this->_raw = (1 << (exp + Fixed::_nbits - 1));
	// this->_raw += frac_bits << (exp - valid_int_nbits + 1);

	/* fixed 구하기 1*/
	int fixed_1(0);
	// if (exp < 0)
	// 	fixed_1 = ((1 << fixed::frac_nbits) | frac_bits) >> exp;
	// else
	// 	fixed_1 = ((1 << fixed::frac_nbits) | frac_bits) << exp;
	fixed_1 = ((1 << fixed::frac_nbits) | frac_bits) << exp;
	
	/* fixed 구하기 2*/
	int fixed_2(0);
	fixed_2 |= ((1 << exp) + (frac_bits >> (23 - exp))) * (2 ^ exp);
	
	/* fixed 구하기 3*/
	
	
	/* */
	/* */
	
	
	// std::cout << "============" << std::endl;
	// std::cout << ((frac_bits << (9 + exp + 1)) >> (9 + exp)) << std::endl;
	// std::cout << ((frac_bits << (9 + exp + 1)) >> (23 - 8 - exp + 9 + exp)) << std::endl;
	// std::cout << "frac_bits : " << ((frac_bits << (9 + exp + 1)) >> (32 - 8)) << std::endl;
	std::cout << "============" << std::endl;
		
	int fixed(0);
	fixed |= ((frac_bits >> (23 - exp)) + (1 << exp) ) << 8;
	std::cout << "fixed : " << fixed << std::endl;
	// fixed |= ((frac_bits << (9 + exp + 1)) >> (9 + exp));
	fixed |= ((frac_bits << (9 + exp + 1)) >> (32 - 8));
	if (*p & (1 << 31))
		fixed |= (1 << 31);
	std::cout << "(float)fixed : " << static_cast<float>(fixed) << std::endl;
	std::cout << "fixed to float : " << (static_cast<float>(fixed) / (1 << 8)) << std::endl;
	// for (int i = 0; i < 23; i ++){
	// 	if (num & *tmpp){
	// 		tmpe = 127 + i;
	// 		std::cout << "tmpe : " << tmpe << std::endl;
	// 		break;
	// 	}
	// 	num = num << 1;
	// }

	// std::cout << "[" << f << "] exp : " << exp << std::endl;
	// if (frac_bits >> (23 - exp + 1) & 1)
	// 	exp += 1;
}


/* fixed pointer number */
// {
// 	if (f) {
// 		int *p = (int *)(&f);
// 		int exp(((*p & fixed::exp_bits_mask) >> 23) - 127);
// 		if (exp < 0)
// 			std::cout << "exp < 0  " << exp << std::endl;
// 		int	frac_bits(*p & fixed::frac_bits_mask);
// 		this->_raw = ((1 << fixed::frac_nbits) | frac_bits) << exp;
// 		// this->_raw |= ((1 << exp) + (frac_bits >> (23 - exp))) * (2 ^ exp);
// 		// this->_raw |= ((1 << exp) + (frac_bits >> (23 - exp))) << Fixed::_nbits;
// 		// int tmp = (((frac_bits >> (23 - exp)) + (1 << exp) ) << Fixed::_nbits);
// 		// tmp < 0 ? this->_raw -= tmp : this->_raw += tmp;
// 		// this->_raw |= ((frac_bits << (fixed::none_frac_nbits + exp)) >> (32 - Fixed::_nbits));
// 		// int tmp = ((frac_bits << (9 + exp)) >> (32 - Fixed::_nbits));
// 		// tmp < 0 ? this->_raw -= tmp : this->_raw += tmp;
// 		if (*p & fixed::sign_bit)
// 			this->_raw = ~this->_raw + 1;

// 		// this->_raw = (1 << fixed::frac_nbits) | (*p & fixed::frac_bits_mask); // 1 추가 + mantissa 부분 추출
// 		// const int pshift = fixed::frac_nbits - (exp + Fixed::_nbits);
// 		// // this->_raw += _bitShift(1,  pshift - 1); // 반올림
// 		// this->_raw += (pshift - 1) > 0 ? 1 << (pshift - 1) : 1 >> (1- pshift);
// 		// // this->_raw = _bitShift(this->_raw, -pshift); // fixed 으로 이동하기
// 		// this->_raw = pshift < 0 ? 1 << -pshift : 1 >> pshift;
// 		// this->_raw = !(*p & fixed::sign_bit) ? this->_raw : ~this->_raw + 1 ; // 음수면 2의 보수
// 	}
// }