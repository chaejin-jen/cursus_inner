#pragma once
#ifndef __RBTREE_H__
#define __RBTREE_H__

#include "ft_BinaryTree.tpp"
#include <iostream>
#include <typeinfo>
#include "ft_utility.hpp"
//#include <cstdlib>

/*
insertfix
	red itself
	case 1 : red parent, red uncle
	case 2 : red parent, black uncle
*/

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
	void insert(T key){
		BinaryTree::insert(key);
		insertfix(target);
	}
	void del(key_type key);

private:
	void insertfix(Node *target){
		if (root == target){
			target->red = false;
			return;
		}
		Node *u, *g; // uncle, grand parent
		// red - red
		while (target->parent && target->parent->red){
			g = target->parent->parent;
			if (g->left == target->parent){
				if (g->right){
					u = g->right;
					// case 1
					if (u->red){
						target->parent->red = false;
						u->red = false;
						g->red = true;
						target = g;
					}
					//else // violation before insert
					//	std::cout << "rbtree : somthing wrong before insert" << std::endl;
				}
				// case 2
				else{
					if (target->parent->right == target){
						t = target->parent;
						leftrotate(target);
					}
					target->parent->red = false;
					g->red = true;
					rightrotate(g);
				}
			}
			else{
				if (g->left){
					u = g->left;
					// case 1
					if (u->red){
						target->parent->red = false;
						u->red = false;
						g->red = true;
						target = g;
					}
					//else // violation before insert
					//	std::cout << "rbtree : somthing wrong before insert" << std::endl;
				}
				// case 2
				else{
					if (target->parent->left == target){
						target = target->parent;
						rightrotate(target);
					}
					target->parent->red = false;
					g->red = true;
					leftrotate(g);
				}
			}
			root->red = false;
		}
	}
	void delfix(Node *target);
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
