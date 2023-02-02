#pragma once
#ifndef __RBTREE_H__
#define __RBTREE_H__

#include "ft_BinaryTree.tpp"
#include <iostream>
#include <typeinfo>
#include "ft_utility.hpp"
//#include <cstdlib>

namespace ft{

namespace rbt{
enum e_color {
		RED,
		BLACK
	};
}

template <typename T>
struct RBTreeNode{
	T key;
	RBTreeNode<T>* parent;
	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	bool red;

	typedef typename T& reference;
	typedef typename T* pointer;

	RBTreeNode()
		: key(), parent(NULL), left(NULL), right(NULL), red(true){
		//std::memset(&key, 0, sizeof(T));
	}
	RBTreeNode(const T& key)
		: key(key), parent(NULL), left(NULL), right(NULL), red(true){}
	//RBTreeNode& operator=(RBTreeNode<T>& x) {
	//	if (this == &x)
	//		return *this;
	//	*this = *x
	//	return *this;
	//};
	reference operator*() const{
		return key;
	}
	pointer operator->() const{
		return &(operator*());
	}
};

template <typename T>
class rbtree : public BinaryTree<RBTreeNode<T> >{
public:
	typedef typename RBTreeNode<T> Node;

	rbtree() : root(NULL) {};
	rbtree(const rbtree<T>& x) {
		*this = x;
	};
	rbtree& operator=(const rbtree<T>& x) {
		if (this == &x)
			return *this;
		BinaryTree::operator=(x);
	};
	void insert(T key);
	void insertfix(Node *target);
	void leftrotate(Node *target);
	void rightrotate(Node *target);
	void del(key_type key);
	void delfix(Node *);
};



template <typename T>
std::ostream& operator<<(std::ostream& out, const RBTreeNode<T>& node) {
	if node.red
		out << "🔴";
	else
		out << "⚫"; // ⚪
	if (typeid(typename RBTreeNode<T>::key) == typeid(ft::pair))
		out << '<' << (*node).first << ',' << (*node).second << '>';
	else
		out << *node;
	return (out);
}

}

#endif /* __RBTREE_H__ */
