#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void){
	//{
	//	typedef std::allocator<int> allocator_type;
	//	typedef allocator_type::pointer pointer;
	//	allocator_type alloc;
	//	pointer a, b;
	//	for (int i = -1; i < 3; i++)
	//	{
	//		try{
	//			cout << "i: " << i;
	//			a = b = alloc.allocate(i);
	//			cout << ", a: " << a
	//				<< ", b: " << b << endl;
	//			cout << "allocate\n\t*a: " << *a
	//				<< ", *b: " << *b << endl;
	//			alloc.construct(a, 100);
	//			cout << "construct\n\t*a: " << *a
	//				<< ", *b: " << *b << endl;
	//			alloc.destroy(a);
	//			cout << "destroy\n\t*a: " << *a
	//				<< ", *b: " << *b << endl;
	//			alloc.deallocate(a, i);
	//			cout << "deallocate\n\t*a: " << *a
	//				<< ", *b: " << *b << endl;
	//		}catch(const std::exception& e){
	//			std::cerr << "\033[90;0m" << e.what() << '\n';
	//		}
	//	}
	//}

	{
		typedef std::allocator<std::string> allocator_type;
		typedef allocator_type::pointer pointer;
		allocator_type alloc;
		pointer a, b;
		for (int i = 0; i < 3; i++)
		{
			try{
				cout << "i: " << i;
				a = b = alloc.allocate(i);
				cout << ", a: " << a
					<< ", b: " << b << endl;
				cout << "allocate" << std::endl << "\t*a: ";
				cout << *a
					<< ", *b: " << *b << endl;
				std::string str("abcdef");
				std::string *str_ptr = &str;
				str_ptr->~basic_string();
				//alloc.construct(a, std::string("hi hey ho"));
				alloc.construct(a, str);
				cout << "construct" << std::endl << "\t*a: ";
				cout << *a
					<< ", *b: " << *b << endl;
				alloc.destroy(a);
				cout << "destroy" << std::endl << "\t*a: ";
				cout << *a
					<< ", *b: " << *b << endl;
				alloc.deallocate(a, i);
				cout << "deallocate" << std::endl << "\t*a: ";
				cout << *a
					<< ", *b: " << *b << endl;
			}catch(const std::exception& e){
				std::cerr << "\033[90;0m" << e.what() << '\n';
				continue;
			}
		}
	}
	system("leaks a.out");

	//cout << c << endl;
	return 0;
}
