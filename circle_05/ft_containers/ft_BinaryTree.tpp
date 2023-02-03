#pragma once
#ifndef __FT_BINARYTREE_TPP__
#define __FT_BINARYTREE_TPP__

#include <iostream>
#include <cmath>

namespace ft{

template <typename Node>
class BinaryTree{

public:
	typedef typename Node::key key_type;
	typedef size_t size_type;

	BinaryTree() : node(NULL) {};
	virtual ~BinaryTree() {};
	BinaryTree& operator=(BinaryTree<T>& x) {
		if (this == &x)
			return *this;
		clear();
		copy_tree(&root, x.root);
	};
	virtual void insert(key_type key) = 0;
	virtual void insertfix(Node *) = 0;
	virtual void del(key_type key) = 0;
	virtual void delfix(Node *) = 0;
	void leftrotate(Node *target){ // Biased to the right about target
		if (target->right == NULL)
			return ;
		Node *center = target->right;
		if (target->parent->right == target)
			target->parent->right = center;
		else
			target->parent->left = center;
		target->right = center->left;
		if (center->left)
			center->left->parent = target;
		center->prarent = target->parent;
		if (center->prarent == NULL)
			root = center;
		target->parent = center;
		center->left = target;
	}
	void rightrotate(Node *target){ // Biased to the left about target
		if (target->left == NULL)
			return ;
		Node *center = target->left;
		if (target->parent->left == target)
			target->parent->left = center;
		else
			target->parent->right = center;
		target->left = center->right;
		if (center->right)
			center->right->parent = target;
		center->prarent = target->parent;
		if (center->prarent == NULL)
			root = center;
		target->parent = center;
		center->right = target;
	}
	void search(key_type key){
		if(root == NULL){
			std::cout <<"Empty." << std::endl;
			return  ;
		}
		Node *curr = root;
		bool found = false;
		while(curr && !found){
			if(curr->key == key)
				found = true;
			if(!found){
				if(curr->key < key)
					curr = curr->right;
				else
					curr = curr->left;
			}
		}
		if(!found){
			std::cout << "Element Not Found." << std::endl;
			return ;
		}
		else{
			std::cout << "FOUND NODE: ";
			std::cout << curr;
			if(curr->parent)
				std::cout << "\t Parent: "<< p->parent->key;
			else
				std::cout << "✗";
			if(curr->right)
				std::cout << "\t Right Child: "<< curr->right->key;
			else
				std::cout << "✗";
			if(curr->left)
				std::cout << "\t Left Child: "<< curr->left->key;
			else
				std::cout << "✗";
			std::cout << std::endl;
		}
	}
	void preorder(Node *node){
		std::cout << node << " ";
		if (node->left) {
			preorder(node->left);
		}
		if (node->right) {
			preorder(node->right);
		}
	}
	void inorder(char node){
		if (node->left) {
			inorder(node->left);
		}
		std::cout << node << " ";
		if (node->right) {
			inorder(node->right);
		}
	}
	void postorder(char node){
		if (node->left) {
			postorder(node->left);
		}
		if (node->right) {
			postorder(node->right);
		}
		std::cout << node << " ";
	}
	Node* successor(Node *node){
		node *y;
		if(node->left)
			y =  find_max(node->left);
		else
			y =  find_min(node->right);
		return y;
	}
	Node* predecessor(Node* node){
		if (root == NULL)
			return NULL;
		node *curr = root;
		node *y;
		while (curr){
			if (node->key < curr->key)
				curr = curr->left;
			else if (node->key > curr->key){
				y = curr;
				curr = curr->right;
			}
			else {
				if (curr->left)
					y = find_max(curr->left);
				break;
			}
		}
		return y;
	}
	void display(){
		size_type h = height(root);
		size_type col = getcol(h);
		key_type **arr = new key_type*[h];
		for (int i = 0; i < h; i++)
			arr[i] = new key_type[col];
		print_tree(arr, root, col / 2, 0, h)
		for (int i = 0; i < h; i++)
			for (int j = 0; j < col; j++)
				if (arr[i][j])
					std::cout << arr[i][j] << " ";
				else:
					std::cout << "  ";
		std::cout << std::endl;
		for (int i = 0; i < h; i++)
			delete[] arr[i];
		delete[] arr;
	}
	void clear() {
		delete_tree(root);
		root = NULL;
	}

protected:
	Node *root;

private:
	size_type height(Node *root){
		if (!root)
			return 0;
		return std::max(height(root->left), height(root->right)) + 1;
	}
	size_type getcol(size_type h){
		if (h == 1)
			return 1;
		return getcol(h - 1) + getcol(h - 1) + 1;
	}
	void print_tree(key_type **arr, Node *node, size_type col, size_type row, size_type height){
		if (!node)
			return ;
		arr[row][col] = node->key
		print_tree(arr, node->left, col - std::pow(2, height - 2), row + 1, height - 1)
		print_tree(arr, node->right, col + std::pow(2, height - 2), row + 1, height - 1)
	}
	void delete_tree(Node *node){
		if(node){
			delete_tree(node->left);
			delete_tree(node->right);
			delete[] node;
		}
	}
	void copy_tree(Node **dst, Node *src){
		if(src){
			*dst = new Node(src->key);
			copy_tree(&dst->left, src->left);
			copy_tree(&dst->right, src->right);
		}
	}
	Node* find_min(Node* node)
	{
		while (node->left) {
			node = node->left;
		}
		return node;
	}
	Node* find_max(Node* node)
	{
		while (node->right) {
			node = node->right;
		}
		return node;
	}

};

}

#endif /* __FT_BINARYTREE_TPP__ */
