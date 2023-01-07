struct A1
{
	virtual ~A1() {}
	int a;
	int a1;
};

struct A2
{
	virtual ~A2() {}
	int a;
	int a1;
	int a2;
};

struct A3
{
	virtual ~A3() {}
	int a;
};

struct B : A1, A2, A3
{
	int a;
	int a1;
	int a2;
	int a3;
	int a4;
	int a5;
};

#include <iostream>
#include <string>

int main()
{
	B* pb = new B;
	A1* pa1 = pb;
	A2* pa2 = pb;
	A3* pa3 = pb;
	std::cout << "pb0: " << (void*)pb << std::endl;
	std::cout << "pa1: " << (void*)pa1 << std::endl;
	std::cout << "pa2: " << (void*)pa2 << std::endl;
	std::cout << "pa2: " << (void*)pa3 << std::endl;
	B* pb_a2 = reinterpret_cast<B*>(pa2);
	std::cout << "back: " << (void*)pb_a2 << std::endl;
	return 0;
}