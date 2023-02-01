#include "test.h"
#include "vector.hpp"
//#include <cstdlib>

//#include <vector>
//namespace ft = std;

void vec::test_constructor()
{
	::std::cout << "\n\n======= vector test_constructor =======" << ::std::endl;
	{
		::ft::vector<int> vec1(0);
		::std::cout << "vec1(0).size()" << (vec1.size()) << ::std::endl;
	}
	{
		::ft::vector<int> vec2(20, 1);
		::std::cout << "v(20,1)" << (vec2.size()) << ::std::endl;
		putElements(vec2.begin(), vec2.end());
	}
	::ft::vector<int> vector_a(5);
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
	::std::cout << "\n\n======= vector test_capacity =======" << ::std::endl;
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
	putElements(vector_a.rbegin(), vector_a.rend());
}

void vec::test_swap()
{
	::std::cout << "\n\n======= vector test_swap =======" << ::std::endl;
	::ft::vector<int> vector_a(5, 100);
	::ft::vector<int> vector_b(3, 11);
	::std::cout << "a: ";
	putElements(vector_a.begin(), vector_a.end());
		::std::cout << "b: ";
	putElements(vector_b.begin(), vector_b.end());
	::std::cout << "\n\n\" vector_b.swap(vector_a) \"" << ::std::endl;
	vector_b.swap(vector_a);
	::std::cout << "a: ";
	putElements(vector_a.begin(), vector_a.end());
	::std::cout << "\tsize: " << vector_a.size() << ::std::endl;
	::std::cout << "\tcapacity: " << vector_a.capacity() << ::std::endl;
	::std::cout << "b: ";
	putElements(vector_b.begin(), vector_b.end());
	::std::cout << "\tsize: " << vector_b.size() << ::std::endl;
	::std::cout << "\tcapacity: " << vector_b.capacity() << ::std::endl;

	::std::cout << "\n\n\" ::ft::swap(vector_a, vector_b); \" " << ::std::endl;
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
	::std::cout << "\n\n======= vector test_vvector =======" << ::std::endl;
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

		::std::cout << "\n\n\"vvector_b.swap(vvector_a)\"" << ::std::endl;
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
	::std::cout << "\n\n======= vector test_operator =======" << ::std::endl;
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

void vec::test_element_access()
{
	{
		::std::cout << "\n\n======= test_element_access =======" << ::std::endl;
		size_t vec_size = 8;
		//vec_size = 1; // vec1.at(2) makes throw std::out_of_range
		//vec_size = 0; // vec1.front() makes segfault
		::ft::vector<int> vec1(vec_size);
		srand(time(NULL));
		for (int i = 0; i < vec_size; i++){
			vec1[i] = (int)(rand()) % 10000;
		}
		::ft::vector<int> const c_vec1(vec1);
		::ft::vector<int> &r_vec1 = vec1;
		::ft::vector<int> const &cr_vec1 = c_vec1;

		::std::cout << "vec1: ";
		putElements(vec1.begin(), vec1.end());

		::std::cout << "\033[0;92mfront()\033[0m" << ::std::endl;
		::std::cout << "vec1: " << vec1.front() << ::std::endl;
		::std::cout << "c_vec1: " << c_vec1.front() << ::std::endl;
		::std::cout << "r_vec1: " << r_vec1.front() << ::std::endl;
		::std::cout << "cr_vec1: " << cr_vec1.front() << ::std::endl;

		::std::cout << "\033[0;92m[1]\033[0m" << ::std::endl;
		::std::cout << "vec1: " << vec1[1] << ::std::endl;
		::std::cout << "c_vec1: " << c_vec1[1] << ::std::endl;
		::std::cout << "r_vec1: " << r_vec1[1] << ::std::endl;
		::std::cout << "cr_vec1: " << cr_vec1[1] << ::std::endl;

		try{
		::std::cout << "\033[0;92mat(2)\033[0m" << ::std::endl;
			::std::cout << "vec1: " << vec1.at(2) << ::std::endl;
			::std::cout << "c_vec1: " << c_vec1.at(2) << ::std::endl;
			::std::cout << "r_vec1: " << r_vec1.at(2) << ::std::endl;
			::std::cout << "cr_vec1: " << cr_vec1.at(2) << ::std::endl;
		}catch(const std::exception &e){
			::std::cerr << e.what() << ::std::endl;
		}

		::std::cout << "\033[0;92mback()\033[0m" << ::std::endl;
		::std::cout << "vec1: " << vec1.back() << ::std::endl;
		::std::cout << "c_vec1: " << c_vec1.back() << ::std::endl;
		::std::cout << "r_vec1: " << r_vec1.back() << ::std::endl;
		::std::cout << "cr_vec1: " << cr_vec1.back() << ::std::endl;
	}
}

void vec::test_modifiers()
{
	::std::cout << "\n\n======= vector test_modifiers =======" << ::std::endl;
	srand(time(NULL));
	{
		::std::cout << "\033[0;92mpush_back (check capacity)\033[0m" << ::std::endl;
		::ft::vector<int> vec1;
		size_t cap(vec1.capacity());
		for (int i = 0; i < 100 ; i++){
			int n = rand() & 1000;
			vec1.push_back(n);
			::std::cout << n << " ";
			//if (cap < vec1.capacity()){
			//	cap = vec1.capacity();
			//	::std::cout << i << " (size) " << vec1.size()
			//		<< " (cap) "  << vec1.capacity() << ::std::endl;
			//}
		}
		::std::cout << ::std::endl;
		putElements(vec1.begin(), vec1.end());
	}

	{
		::std::cout << "\033[0;92minsert(position, value)\033[0m" << ::std::endl;
		::ft::vector<int> vec1;
		//::ft::vector<int> vec1(5, 20);
		::std::cout << "(size) " << vec1.size()
			<< " (cap) "  << vec1.capacity() << ": ";
		putElements(vec1.begin(), vec1.end());

		vec1.insert(vec1.begin() + vec1.size(), -1);
		//vec1.insert(vec1.begin() + vec1.size() + 1, 0);  // segmentation fault
		vec1.insert(vec1.begin(), 1);
		vec1.insert(vec1.begin(), 2);
		vec1.insert(vec1.begin(), 3);
		vec1.insert(vec1.begin(), 4);
		vec1.insert(vec1.begin(), 5);
		::std::cout << "(size) " << vec1.size()
			<< " (cap) "  << vec1.capacity() << '\n';
		putElements(vec1.begin(), vec1.end());
	}

	{
		::std::cout << "\033[0;92minsert(position, first, last)\033[0m" << ::std::endl;
		::ft::vector<int> vec1;
		::ft::vector<int> vec2;
		for (int i = 0; i < 20 ; i++){
			//int n = rand() & 1000;
			//vec1.push_back(n);
			vec1.push_back(i);
		}
		::std::cout << "vec1 (size) " << vec1.size()
			<< " (cap) "  << vec1.capacity() << "\n\t";
		putElements(vec1.begin(), vec1.end());

		vec2.insert(vec2.begin(), vec1.begin() + 1, vec1.begin() + 5); // 1 2 3 4
		vec2.insert(vec2.begin() + 2, vec1.begin(), vec1.end()); // 1 2 0...19 3 4
		vec2.insert(vec2.end(), vec1.begin(), vec1.end()); // 1 2 0...19 3 4 0...19
		::std::cout << "vec2 : (size) " << vec2.size()
			<< " (cap) "  << vec2.capacity() << "\n\t";
		putElements(vec2.begin(), vec2.end());
	}

	{
		::std::cout << "\033[0;92merase(position)\033[0m" << ::std::endl;
		::ft::vector<int> vec1;
		for (int i = 0; i < 20 ; i++){
			//int n = rand() & 1000;
			//vec1.push_back(n);
			vec1.push_back(i);
		}
		::std::cout << "vec1 (size) " << vec1.size()
			<< " (cap) "  << vec1.capacity() << "\n\t";
		putElements(vec1.begin(), vec1.end());
		vec1.erase(vec1.begin() + 2);
		vec1.erase(vec1.begin());
		vec1.erase(vec1.end() - 1);
		//vec1.erase(vec1.end()); // segmentation fault
		::std::cout << "vec1 : (size) " << vec1.size()
			<< " (cap) "  << vec1.capacity() << "\n\t";
		putElements(vec1.begin(), vec1.end());
	}

	{
		::std::cout << "\033[0;92merase(first, last)\033[0m" << ::std::endl;
		::ft::vector<int> vec1;
		for (int i = 0; i < 20 ; i++){
			int n = rand() & 1000;
			vec1.push_back(n);
		}
		::std::cout << "vec1 (size) " << vec1.size()
			<< " (cap) "  << vec1.capacity() << "\n\t";
		putElements(vec1.begin(), vec1.end());
		vec1.erase(vec1.begin() + 7, vec1.begin() + 15); // [vec1[7] ~ vec1[15])
		//vec1.erase(vec1.begin(), vec1.begin()); // noting change
		::std::cout << "vec1 : (size) " << vec1.size()
			<< " (cap) "  << vec1.capacity() << "\n\t";
		putElements(vec1.begin(), vec1.end());
	}
}



