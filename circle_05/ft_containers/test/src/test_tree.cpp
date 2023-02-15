#include <memory>
#include <iostream>
#include <typeinfo>
// #include <type_traits>

#include "ft_tree.hpp"
#include "ft_utility.hpp"
#include "map.hpp"
#include <list>

struct A{};

#include <iostream>

int main(){
	typedef const int Key;
	typedef int       Tp;
	typedef ft::pair<Key, Tp> value_type;
	typedef ::std::less<Key> Compare;
	typedef ::std::allocator<ft::pair<const Key, Tp> > Alloc;

	typedef ft::tree_node<value_type> node;
	typedef node* node_pointer;
	typedef std::allocator<node>      node_allocator;

	node_allocator __na;
	{
		Compare comp;
		Compare& value_comp = comp;
		// Alloc a;

		node_pointer __h = __na.allocate(1);
		value_type __v(ft::make_pair(111, 222));
		ft::construct(ft::addressof(__h->__value_), __v);

		{
			std::cout << "key, value: "
				<< __h->__value_.first << ' '
				<< __h->__value_.second << std::endl;
			std::cout << std::endl;
			
			std::cout << "less<Key>, less<Key>(): "
				<< typeid(::std::less<Key>).name() << ' '
				<< typeid(::std::less<Key>()).name() << std::endl;
			// std::cout << typeid(::std::less<Key>).name() << std::endl;
			std::cout << std::endl;

			std::cout << "key compare by std::less: "
				<< "std::less<Key>()()" << std::endl;
			std::cout << (::std::less<Key>()(1, __h->__value_.first)) << ' '
				<< (::std::less<Key>()(__v.first, __h->__value_.first)) << ' '
				<< (::std::less<Key>()(99999, __h->__value_.first)) << std::endl;

			std::cout << (comp(1, __h->__value_.first)) << ' '
				<< (comp(__v.first, __h->__value_.first)) << ' '
				<< (comp(99999, __h->__value_.first)) << std::endl;

			std::cout << (value_comp(1, __h->__value_.first)) << ' '
				<< (value_comp(__v.first, __h->__value_.first)) << ' '
				<< (value_comp(99999, __h->__value_.first)) << std::endl;
			// CHECK
			// std::cout << (value_comp(__v, __h->__value_)) << std::endl;
		}
			std::cout << std::endl;
		{
			typedef ft::tree_node_destructor<node_allocator> Dp;

			std::cout << "node_allocator: \n\t"
				<< typeid(node_allocator).name() << std::endl;
			std::cout << "node_allocator::value_type: \n\t"
				<< typeid(node_allocator::value_type).name() << std::endl;
			std::cout << "node_pointer: \n\t"
				<< typeid(node_allocator::pointer).name() << "\n\t";
			std::cout << typeid(Dp::pointer).name() << "\n\t";
			std::cout << typeid(node_pointer).name() << std::endl;
			std::cout << std::endl;
		}
	}

	typedef ft::map_value_compare<Key, Tp, Compare>  __vc;
	typedef ft::pair<ft::remove_const<Key>, Tp> __value_type;
	typedef std::allocator<__value_type>        __allocator_type;

	__vc             __comp;
	__allocator_type __a;
	{
		__vc  __comp;
		__vc& __value_comp = __comp;

		// node_allocator __na;
		node_pointer __h2 = __na.allocate(1);
		value_type __v1(ft::make_pair(111, 222));
		value_type __v2(ft::make_pair(333, 444));
		ft::construct(ft::addressof(__h2->__value_), __v2);

		std::cout << "value comp " << (__value_comp(__v1, __h2->__value_)) << std::endl; 
		std::cout << "value comp " << (__value_comp(__v2, __h2->__value_)) << std::endl; 

		// typedef ft::tree_node<value_type> node;
		// typedef node* node_pointer;
		// typedef std::allocator<node>      node_allocator;

		// node_allocator __na;
		// node_pointer __h = __na.allocate(1);
		// value_type __v(ft::make_pair(111, 222));
		// ft::construct(ft::addressof(__h->__value_), __v);

		// {
			
		// }
	}

	{
		// <value_type, key_compare, allocator_type>
		// typedef ft::tree<value_type, Compare, __allocator_type>     tree;

		typedef ::ft::tree<value_type, __vc, __allocator_type> tree;
		// typedef ::ft::tree<__value_type, __vc, __allocator_type> tree;
		typedef typename tree::iterator                iterator;
		typedef typename tree::const_iterator          const_iterator;
		
		Compare comp;

		// tree tree1;
		// tree tree1();
		tree tree1(__comp);
		// tree tree1(__a);
		// tree tree1(__comp, __a);

		node_allocator __na;
		node_pointer __h2 = __na.allocate(1);
		value_type __v1(ft::make_pair(111, 222));
		value_type __v2(ft::make_pair(333, 444));
		ft::construct(ft::addressof(__h2->__value_), __v2);

		std::cout << "value comp " << (__comp(__v1, __h2->__value_)) << std::endl; 
		std::cout << "value comp " << (__comp(__v2, __h2->__value_)) << std::endl;

		std::cout << std::endl;

		std::cout << typeid(comp).name() << std::endl;
		std::cout << typeid(__comp).name() << std::endl;
		std::cout << typeid(tree1.value_comp()).name() << std::endl;

		// const __vc& vc = tree1.value_comp();
		// std::cout << (vc(__v2, __h2->__value_)) << std::endl; 
		// std::cout << (tree1.value_comp()(__v2, __h2->__value_)) << std::endl; 

		// std::cout << tree1.size() << std::endl;
		// if (tree1.begin() == tree1.end())
		// 	std::cout << typeid(tree1.begin()).name() << std::endl;
		// else
		//     // std::cout << typeid(*(tree1.begin())->first()).name() << std::endl;
		//     std::cout << typeid((tree1.begin())->first).name() << std::endl;
	}
	{
				
		// typedef ::ft::tree<__value_type, __vc, __allocator_type> tree;
		typedef ::ft::tree<value_type, __vc, __allocator_type> tree;
		typedef typename tree::iterator                iterator;
		typedef typename tree::const_iterator                const_iterator;
		// __value_type __v(ft::make_pair(111, 222)); // CHECK
		{
			tree tree1(__comp);

			std::cout << "tree size: " << tree1.size() << std::endl;
			// tree1.begin();
			// tree1.end();

			value_type __v(ft::make_pair(111, 222));
			tree1.__insert_unique(__v);
			std::cout << "tree size: " << tree1.size() << std::endl;
			
			iterator it = tree1.find(__v);

			std::cout << "find: "
				<< it->first << " " << it->second << std::endl;
		}
		{
			std::list<value_type> lst;
			unsigned int lst_size = 5;
			for (unsigned int i = 0; i < lst_size; ++i)
				lst.push_back(value_type(2.5 + i, i + 1));

			ft::map<Key, Tp> mp(lst.begin(), lst.end());
			ft::map<Key, Tp>::iterator it(mp.begin());
			// ft::map<Key, Tp>::const_iterator ite(mp.begin());
			// for (const_iterator iter = tree1.begin() ; iter !=  tree1.end(); iter++)
			// {
			//     std::cout << iter->first << " " << iter->second << std::endl;
			// }
			// std::cout << std::endl;
			

		}
	}

	std::cout << "tree1 destroy" << std::endl;
	std::cout << "\033[0;90m" << std::endl;
	return 0;
}