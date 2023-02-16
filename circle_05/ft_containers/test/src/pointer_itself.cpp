#include <iostream>

void modify_by_refrence(int* &);


class A{
	const int * ptr;
public:
	A() : ptr(0){}
	A(const int *x) : ptr(x){}
	const int * base() {return ptr;};
	const int *& refbase() {return ptr;};

	const int * next() const{
		const int * tmp(ptr);
		return ++tmp;
	}

	int operator*() const {return *ptr;}
};

int a=4, b=5;
const int i = 100;
const int arr[] = {9, 8, 7};
//A aobj(&i);
A aobj(arr);

int main()
{
	int *ptr = NULL;
	ptr = &a;

	std::cout << "*ptr before modifying by refrence: " << *ptr << std::endl;
	modify_by_refrence(ptr);
	std::cout << "*ptr after modifying by refrence: " << *ptr << std::endl;

	return 0;
}

void modify_by_refrence(int * &ptr) //this function has refrence and hence can modify the pointer;
{
	ptr = const_cast<int*&>(aobj.refbase());
	const int * next = aobj.next();
	std::cout << "next: " << *next << std::endl;
}
