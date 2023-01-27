#include "test.h"
#include "vector.hpp"

//#include <vector>
//namespace ft = std;

void vec::test_constructor()
{
	::ft::vector<int> vector_a(5, 100);
	::ft::vector<int> vector_b(3);
	::ft::vector<int> vector_c(vector_a);
	*(vector_a.begin()) = 77;
	putElements(vector_a.begin(), vector_a.end());
	putElements(vector_b.begin(), vector_b.end());
	putElements(vector_c.begin(), vector_c.end());
	::std::cout << "*(vector_a.rbegin()) = 33;" << ::std::endl;
	*(vector_a.rbegin()) = 33;
	putElements(vector_a.rbegin(), vector_a.rend());
}

void vec::test_capacity()
{
	::ft::vector<int> vector_a(5, 100);
	putElements(vector_a.begin(), vector_a.end());
	::std::cout << "size: " << vector_a.size() << ::std::endl;
	::std::cout << "max_size: " << vector_a.max_size() << ::std::endl;
	::std::cout << "capacity: " << vector_a.capacity() << ::std::endl;
	::std::cout << "do reserve(10)!" << ::std::endl;
	vector_a.reserve(10);
	putElements(vector_a.begin(), vector_a.end());
	::std::cout << "size: " << vector_a.size() << ::std::endl;
	::std::cout << "capacity: " << vector_a.capacity() << ::std::endl;
	::std::cout << "max_size: " << vector_a.max_size() << ::std::endl;
	//putElements(vector_a.rbegin(), vector_a.rend());
}

void vec::test_swap()
{
	::ft::vector<int> vector_a(5, 100);
	::ft::vector<int> vector_b(3, 11);
	::std::cout << "a: ";
	putElements(vector_a.begin(), vector_a.end());
		::std::cout << "b: ";
	putElements(vector_b.begin(), vector_b.end());
	::std::cout << "\n\n======= vector_b.swap(vector_a) =======" << ::std::endl;
	vector_b.swap(vector_a);
	::std::cout << "a: ";
	putElements(vector_a.begin(), vector_a.end());
	::std::cout << "\tsize: " << vector_a.size() << ::std::endl;
	::std::cout << "\tcapacity: " << vector_a.capacity() << ::std::endl;
	::std::cout << "b: ";
	putElements(vector_b.begin(), vector_b.end());
	::std::cout << "\tsize: " << vector_b.size() << ::std::endl;
	::std::cout << "\tcapacity: " << vector_b.capacity() << ::std::endl;

	::std::cout << "\n\n======= ::ft::swap(vector_a, vector_b); =======" << ::std::endl;
	::ft::swap(vector_a, vector_b);
	::std::cout << "a: ";
	putElements(vector_a.begin(), vector_a.end());
	::std::cout << "\tsize: " << vector_a.size() << ::std::endl;
	::std::cout << "\tcapacity: " << vector_a.capacity() << ::std::endl;
	::std::cout << "b: ";
	putElements(vector_b.begin(), vector_b.end());
	::std::cout << "\tsize: " << vector_b.size() << ::std::endl;
	::std::cout << "\tcapacity: " << vector_b.capacity() << ::std::endl;
}

void vec::test_vvector()
{
	{
		::ft::vector<int> vector_a1(10, 100);
		::ft::vector<int> vector_a2(10, 101);
		::ft::vector<int> vector_a3(10, 102);
		::ft::vector<int> vector_a4(10, 103);
		::ft::vector<int> vector_b1(5, 11);
		::ft::vector<int> vector_b2(5, 12);
		::ft::vector<int> vector_b3(5, 13);
		::ft::vector<int> vector_b4(5, 14);

		::std::cout << "st vvector" << ::std::endl;
		::ft::vector< ::ft::vector<int> > vvector_a(4);
		::ft::vector< ::ft::vector<int> > vvector_b(4);
		::std::cout << "fi vvector" << ::std::endl;

		::ft::vector< ::ft::vector<int> >::iterator iter = vvector_a.begin();
		::ft::vector< ::ft::vector<int> >::iterator iter_b = vvector_b.begin();

		::std::cout << "set vvector_a" << ::std::endl;
		*iter = vector_a1;
		*(iter + 1) = vector_a2;
		*(iter + 2) = vector_a3;
		*(iter + 3) = vector_a4;

		::std::cout << "set vvector_b" << ::std::endl;
		*iter_b = vector_b1;
		*(iter_b + 1) = vector_b2;
		*(iter_b + 2) = vector_b3;
		*(iter_b + 3) = vector_b4;

		putElements((*iter).begin(), (*iter).end());
		putElements((*iter_b).begin(), (*iter_b).end());

		::std::cout << "\n\n======= vvector_b.swap(vvector_a) =======" << ::std::endl;
		vvector_b.swap(vvector_a);
		::std::cout << "a: ";
		putElements((*iter).begin(), (*iter).end());
		putElements((*(iter + 1)).begin(), (*(iter + 1)).end());
		putElements((*(iter + 2)).begin(), (*(iter + 2)).end());
		putElements((*(iter + 3)).begin(), (*(iter + 3)).end());
		::std::cout << "\tsize: " << vvector_a.size() << ::std::endl;
		::std::cout << "\tcapacity: " << vvector_a.capacity() << ::std::endl;
		::std::cout << "b: ";
		putElements((*iter_b).begin(), (*iter_b).end());
		putElements((*(iter_b + 1)).begin(), (*(iter_b + 1)).end());
		putElements((*(iter_b + 2)).begin(), (*(iter_b + 2)).end());
		putElements((*(iter_b + 3)).begin(), (*(iter_b + 3)).end());
		::std::cout << "\tsize: " << vvector_b.size() << ::std::endl;
		::std::cout << "\tcapacity: " << vvector_b.capacity() << ::std::endl;
	}
}

void vec::test_operator()
{
	{
		::ft::vector<int> vector_a1(10, 100);
		::ft::vector<int> vector_a2(10, 101);
		::ft::vector<int> vector_a3(10, 102);
		::ft::vector<int> vector_a4(10, 103);
		::ft::vector<int> vector_b1(5, 102);
		::ft::vector<int> vector_b2(5, 12);
		::ft::vector<int> vector_b3(5, 13);
		::ft::vector<int> vector_b4(5, 14);

		::ft::vector< ::ft::vector<int> > vv_b3(4, vector_a1);
		::ft::vector< ::ft::vector<int> > vv_b4(4, vector_a1);
		::ft::vector< ::ft::vector<int> >::iterator iter1 = vv_b3.begin();
		::ft::vector< ::ft::vector<int> >::iterator iter2 = vv_b4.begin();
		*(vv_b3.end() - 1) = vector_b3;
		*(vv_b4.end() - 1) = vector_b4;

		::std::cout << "vector(10, 100) < vector(10, 101) : "
			<< (vector_a1 < vector_a2) << ::std::endl;
		::std::cout << "vector(10, 102) < vector(5, 102) : "
			<< (vector_a3 < vector_b1) << ::std::endl;
		::std::cout << "vector(5, 13) == vector(5, 12) : "
			<< (vector_b3 == vector_b2) << ::std::endl;
		::std::cout << "vector(5, 14) >= vector(10, 103) : "
			<< (vector_b4 >= vector_a4) << ::std::endl;
		::std::cout << "vector(5, 14) == vector(5, 14) : "
			<< (vector_b4 == vector_b4) << ::std::endl;
		::std::cout << "vvetor...b3(5, 13) == vvetor...b3(5, 14) : "
			<< (vv_b3 == vv_b4) << ::std::endl;
		::std::cout << "vvetor...b3(5, 13) <= vvetor...b3(5, 14) : "
			<< (vv_b3 <= vv_b4) << ::std::endl;
	}
}
