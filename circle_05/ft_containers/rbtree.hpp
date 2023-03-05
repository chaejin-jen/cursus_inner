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
delfix
	black itself
	case 1 : red sibling
	case 2 : black sibling, black sibling-children
	case 3 : black sibling, red left s-child, black right s-child
	case 4 : black sibling, black left s-child, red right s-child
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
	void del(key_type key){
		Node *x(NULL);
		Node *target = find(key);
		bool del_red = target->red;

		if (target == NULL){
			return ;
		}
		if (target->left == NULL){
			x = target->right;
			transplant(target, x);
		}
		else if (target->left){
			x = target->left;
			transplant(target, x);
		}
		else{
			Node *y = successor(target);
			del_red = y->red;

			if y->p != target{
				transplant(y, y->right);
				y->right = target->right;
				y->right->parent = y;
			}
			transplant(target, x);
			y->left = target->left;
			y->left->parent = y;
		}
		delete target;  // delete target->key
		if (del_red == false)
			delfix(x);
	}

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
	void delfix(Node *target){
		node *s; // sibling

		while (target != root && !target->red){
			if (target->parent->left == target){
				s = target->parent->right;
				// case 1
				if (s->red){
					s->red = false;
					target->parent->red = true;
					leftrotate(target->parent);
					s = target->parent->right;
				}
				// case 2
				if (!s->right->red && !s->left->red){
					s->red = true;
					target = target->parent;
				}
				else{
					// case 3
					if (!s->right->red){
						s->left->red = false;
						s->red = true;
						rightrotate(s);
						s = target->parent->right;
					}
					// case 4
					s->red = target->parent->red;
					target->parent->red = false;
					s->right->red = false;
					leftrotate(target->parent);
					target = root;
				}
			}
			else{
				s = target->parent->left;
				// case 1
				if (s->red){
					s->red = false;
					target->parent->red = true;
					rightrotate(target->parent);
					s = target->parent->left;
				}
				// case 2
				if (!s->left->red && !s->right->red){
					s->red = true;
					target = target->parent;
				}
				else{
					// case 3
					if (!s->left->red){
						s->right->red = false;
						s->red = true;
						leftrotate(s);
						s = target->parent->left;
					}
					// case 4
					s->red = target->parent->red;
					target->parent->red = false;
					s->left->red = false;
					rightrotate(target->parent);
					target = root;
				}
			}
			target->red = false;
			root->red = false;
		}
	}
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
