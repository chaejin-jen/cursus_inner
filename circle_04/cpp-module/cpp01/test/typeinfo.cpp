#include <iostream>
#include <typeinfo>

class Parent
{
public:
	virtual void PrintMe() { std::cout << "I am Parent" << std::endl; }
};

class Child : public Parent
{
private:
	int num;

public:
	Child(int anum) : num(anum) {}
	virtual void PrintMe() { std::cout << "I am Child\n" << std::endl; }
	void PrintNum() { std::cout << "Hello Child = " << num << std::endl; }
};

void func(){}

int main()
{
	Parent P, * pP;
	Child C(123), * pC;
	pP = &P;
	pC = &C;

	int val;

	std::cout << "typeid = "<< typeid(typeid(P).name()).name() << std::endl;
	std::cout << "P = "<< typeid(P).name()
		<< ", pP = " << typeid(pP).name()
		<< ", *pP = " << typeid(*pP).name() << std::endl;
	
	if (strcmp(typeid(P).name(), "6Parent") == 0)
		std::cout << "YY" << std::endl;
	else
		std::cout << "NN" << std::endl;

	std::cout << "C = "<< typeid(C).name()
		<< ", pC = " << typeid(pC).name()
		<< ", *pC = " << typeid(*pC).name() << std::endl;

	pP = &C;
	std::cout << "pP = "<< typeid(pP).name()
		<< ", *pP = " << typeid(*pP).name()
		<< ", val = " << typeid(val).name() << std::endl;

	std::cout << "func = " << typeid(func).name() << std::endl;  // 함수의 타입 확인 (cdecl : 함수 규약)
}
