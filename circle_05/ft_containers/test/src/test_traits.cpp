#include <memory>
#include <iostream>
#include <type_traits>

#include "ft_tree.hpp"
#include "map.hpp"

struct A{};

int main(){

	typedef const int Key;
	typedef int       Tp;
	typedef ft::pair<Key, Tp> value_type;
	typedef ::std::less<Key> Compare;
	typedef ::std::allocator<ft::pair<const Key, Tp> > Alloc;

	typedef ft::tree_node<value_type> node;
	typedef node* node_pointer;
	typedef std::allocator<node>      node_allocator;

	typedef ft::map_value_compare<Key, Tp, Compare>  __vc;
	typedef ft::pair<ft::remove_const<Key>, Tp> __value_type;
	typedef std::allocator<__value_type>        __allocator_type;

	typedef ::ft::tree<value_type, __vc, __allocator_type> tree;

	std::cout << "std::is_empty<>" << std::endl;
	std::cout << std::is_empty<int>::value << std::endl;
	std::cout << std::is_empty<std::string>::value << std::endl;
	std::cout << std::is_empty<A>::value << std::endl;
	std::cout << std::is_empty<Compare>::value << std::endl;
	std::cout << std::is_empty<tree>::value << std::endl;

	std::cout << "ft::is_empty<>" << std::endl;
	std::cout << ft::is_empty<int>::value << std::endl;
	std::cout << ft::is_empty<std::string>::value << std::endl;
	std::cout << ft::is_empty<A>::value << std::endl;
	std::cout << ft::is_empty<Compare>::value << std::endl;
	std::cout << ft::is_empty<tree>::value << std::endl;

	return 0;
}