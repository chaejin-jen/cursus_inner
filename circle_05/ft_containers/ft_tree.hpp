#pragma once
#ifndef __FT_TREE_H__
#define __FT_TREE_H__

#include <memory>
#include <algorithm>
#include "ft_type_traits.tpp"
#include "ft_iterator.hpp"
#include "ft_tree_utility.hpp"

namespace ft{

template <typename Allocator>
class tree_node_destructor
{
	typedef Allocator                      allocator_type;
	typedef typename Allocator::value_type value_type;
public:
	typedef typename Allocator::pointer pointer;
private:

	allocator_type& __na_;

	tree_node_destructor& operator=(const tree_node_destructor&);

public:
	bool __value_constructed;

	explicit tree_node_destructor(allocator_type& __na)
		: __na_(__na),
		__value_constructed(false){}

	void operator()(pointer __p) {
		if (__value_constructed)
			::ft::destroy(addressof(__p->__value_));
		if (__p)
			__na_.deallocate(__p, 1);
	}
};

// node

template <typename Ptr>
struct tree_end_node
{
	typedef Ptr pointer;
	pointer __left_;

	tree_end_node() : __left_() {}
};

struct tree_node_base : public tree_end_node<tree_node_base *>{
	typedef tree_node_base*        pointer;
	typedef const tree_node_base*  const_pointer;
	typedef tree_end_node<pointer> base;

	pointer __right_;
	pointer __parent_;
	bool    __is_black_;
};

template <typename Tp, typename T = void>
struct tree_node_base_selector{
	typedef tree_node_base type;
};

template <typename Tp>
struct tree_node_base_selector<Tp, typename enable_if<is_const<Tp>::value>::type>{
	typedef const tree_node_base type;
};

template <typename Tp>
struct tree_node : public tree_node_base{
public:
	typedef typename tree_node_base_selector<Tp>::type base;

	typedef Tp value_type;

	value_type __value_;
};

// NodePtr

// Returns:  true if x is a left child of its parent, else false
// Precondition:  x != NULL.
template <typename NodePtr>
bool
tree_is_left_child(NodePtr x)
{
	return x == x->__parent_->__left_;
}

// Returns:  pointer to the left-most node under x.
// Precondition:  x != NULL.
template <typename NodePtr>
NodePtr
tree_min(NodePtr x)
{
	while (x->__left_ != NULL)
		x = x->__left_;
	return x;
}

// Returns:  pointer to the right-most node under x.
// Precondition:  x != NULL.
template <typename NodePtr>
NodePtr
tree_max(NodePtr x)
{
	while (x->__right_ != NULL)
		x = x->__right_;
	return x;
}

// Returns:  pointer to the next in-order node after x.
// Precondition:  x != NULL.
template <typename NodePtr>
NodePtr
tree_next(NodePtr x)
{
	if (x->__right_ != NULL)
		return tree_min(x->__right_);
	while (!tree_is_left_child(x))
		x = x->__parent_;
	return x->__parent_;
}

// Returns:  pointer to the previous in-order node before x.
// Precondition:  x != NULL.
template <typename NodePtr>
NodePtr
tree_prev(NodePtr x)
{
	if (x->__left_ != NULL)
		return tree_max(x->__left_);
	while (tree_is_left_child(x))
		x = x->__parent_;
	return x->__parent_;
}

// Use:  if biased to the right for target x, rotate left about center y
// Effects:  Makes x->__right_ the subtree root with x as its left child
//           while preserving in-order order.
// Precondition:  x->__right_ != NULL
template <typename NodePtr>
void
tree_left_rotate(NodePtr x)
{
	NodePtr y = x->__right_;
	x->__right_ = y->__left_;
	if (x->__right_ != NULL)
		x->__right_->__parent_ = x;
	y->__parent_ = x->__parent_;
	if (tree_is_left_child(x))
		x->__parent_->__left_ = y;
	else
		x->__parent_->__right_ = y;
	y->__left_ = x;
	x->__parent_ = y;
}

// Use:  if biased to the left for target x, rotate right about center y
// Effects:  Makes x->__left_ the subtree root with x as its right child
//           while preserving in-order order.
// Precondition:  x->__left_ != NULL
template <typename NodePtr>
void
tree_right_rotate(NodePtr x)
{
	NodePtr y = x->__left_;
	x->__left_ = y->__right_;
	if (x->__left_ != NULL)
		x->__left_->__parent_ = x;
	y->__parent_ = x->__parent_;
	if (tree_is_left_child(x))
		x->__parent_->__left_ = y;
	else
		x->__parent_->__right_ = y;
	y->__right_ = x;
	x->__parent_ = y;
}

// Effects:  Rebalances root after attaching x to a leaf.
// case: x starts with red color
//      case 1 : red parent, red uncle
//      case 2 : red parent, black uncle
template <typename NodePtr>
void
tree_balance_after_insert(NodePtr root, NodePtr x)
{
	x->__is_black_ = x == root;
	while (x != root && !x->__parent_->__is_black_)
	{
		// double red
		if (tree_is_left_child(x->__parent_))
		{
			NodePtr y = x->__parent_->__parent_->__right_;
			if (y != NULL && !y->__is_black_)
			{
				// case 1
				x = x->__parent_;
				x->__is_black_ = true;        // parent b
				x = x->__parent_;
				x->__is_black_ = x == root; // grand  r
				y->__is_black_ = true;        // uncle  b
			}
			else
			{
				// case 2
				if (!tree_is_left_child(x))
				{
					x = x->__parent_;
					tree_left_rotate(x);
				}
				x = x->__parent_;
				x->__is_black_ = true;        // parent b
				x = x->__parent_;
				x->__is_black_ = false;       // grand  r
				tree_right_rotate(x);
				break;
			}
		}
		else
		{
			NodePtr y = x->__parent_->__parent_->__left_;
			if (y != NULL && !y->__is_black_)
			{
				// case 1
				x = x->__parent_;
				x->__is_black_ = true;        // parent b
				x = x->__parent_;
				x->__is_black_ = x == root; // grand  r
				y->__is_black_ = true;        // uncle  b
			}
			else
			{
				// case 2
				if (tree_is_left_child(x))
				{
					x = x->__parent_;
					tree_right_rotate(x);
				}
				x = x->__parent_;
				x->__is_black_ = true;        // parent b
				x = x->__parent_;
				x->__is_black_ = false;       // grand  r
				tree_left_rotate(x);
				break;
			}
		}
	}
}


// Effects:  Rebalances root after erase x to a leaf. (sibling w)
// case: x starts with black color
//      case 1 : red sibling
//      case 2 : black sibling, black sibling-children
//      case 3 : black sibling, red left s-child, black right s-child
//      case 2 : black sibling, black left s-child, red right s-child
template <typename NodePtr>
void
tree_balance_after_erase(NodePtr x, NodePtr w)
{
	while (x != root && !x->__is_black_)
	{
		if (x->parent->left == x)
		{
			w = x->parent->right;
			if (w->__is_black_)
			{
				// case 1
				w->__is_black_ = true;
				x->parent->__is_black_ = false;
				tree_left_rotate(x->parent);
				w = x->parent->right;
			}
			if (!w->right->__is_black_ && !w->left->__is_black_)
			{
				// case 2
				w->__is_black_ = false;
				x = x->parent;
			}
			else{
				// case 3
				if (!w->right->__is_black_)
				{
					w->left->__is_black_ = true;
					w->__is_black_ = false;
					tree_right_rotate(w);
					w = x->parent->right;
				}
				// case 4
				w->__is_black_ = x->parent->__is_black_;
				x->parent->__is_black_ = true;
				w->right->__is_black_ = true;
				tree_left_rotate(x->parent);
				x = root;
			}
		}
		else{
			w = x->parent->left;
			if (w->__is_black_)
			{
				// case 1
				w->__is_black_ = true;
				x->parent->__is_black_ = false;
				tree_right_rotate(x->parent);
				w = x->parent->left;
			}
			if (!w->left->__is_black_ && !w->right->__is_black_)
			{
				// case 2
				w->__is_black_ = false;
				x = x->parent;
			}
			else{
				// case 3
				if (!w->left->__is_black_)
				{
					w->right->__is_black_ = true;
					w->__is_black_ = false;
					tree_left_rotate(w);
					w = x->parent->left;
				}
				// case 4
				w->__is_black_ = x->parent->__is_black_;
				x->parent->__is_black_ = true;
				w->left->__is_black_ = true;
				tree_right_rotate(x->parent);
				x = root;
			}
		}
		x->__is_black_ = true;
		root->__is_black_ = true;
	}
}

// Effects:  unlinks z from the tree rooted at root, rebalancing as needed.
template <typename NodePtr>
void
tree_remove(NodePtr root, NodePtr z)
{
	// y is z or tree_minimum(z->right)
	NodePtr y = (z->__left_ == NULL || z->__right_ == NULL) ?
					z : tree_next(z);
	// x priority : right_child, left_child, NULL
	NodePtr x = y->__left_ != NULL ? y->__left_ : y->__right_;
	// w is x's possibly null uncle (will become x's sibling)
	NodePtr w = NULL;
	// link child node x to y's parent, and find sibling w
	if (x != NULL)
		x->__parent_ = y->__parent_;
	if (tree_is_left_child(y))
	{
		// (1) y == z  && tree_is_left_child(z)
		// (2) y == tree_next(z) && y != z->right
		y->__parent_->__left_ = x;
		if (y != root)
			w = y->__parent_->__right_;
		else
			root = x;  // w == NULL
	}
	else
	{
		// (1) y == z  && !tree_is_left_child(z)
		// (2) y == z->right
		y->__parent_->__right_ = x;
		w = y->__parent_->__left_;
	}
	bool __removed_black = y->__is_black_;

	if (y != z)
	{
		// when z has children, y == z->right or tree_min(z)
		// link child node y to z's parent
		y->__parent_ = z->__parent_;
		if (tree_is_left_child(z))
			y->__parent_->__left_ = y;
		else
			y->__parent_->__right_ = y;
		y->__left_ = z->__left_;
		y->__left_->__parent_ = y;

		y->__right_ = z->__right_;
		if (y->__right_ != NULL)
			y->__right_->__parent_ = y;
		y->__is_black_ = z->__is_black_;
		if (root == z)
			root = y;
	}
	if (__removed_black && root != NULL)
	{
		if (x == __root || (x != NULL && !x->__is_black_))
		// (1) z-right->__is_black == true
		// (2) tree_min(z)->__is_black == true
			x->__is_black_ = true;
		else
			tree_balance_after_remove(x, w);
	}
	// There is no need to rebalance if we removed a red, or if we removed the last node.
}

// iterator

template <typename Tp, typename NodePtr, typename DiffType = ::std::ptrdiff_t>
class tree_iterator
{
	typedef NodePtr                     node_pointer;
	typedef tree_node<Tp>               node;
	typedef typename node::base         node_base;
	typedef node_base*                  node_base_pointer; // CHECK

	node_pointer __ptr_;

public:
	typedef bidirectional_iterator_tag iterator_category;
	typedef Tp                         value_type;
	typedef DiffType                   difference_type;
	typedef value_type&                reference;
	typedef value_type*                pointer;

	tree_iterator(){}
	explicit tree_iterator(node_pointer __p) : __ptr_(__p) {}

	node_pointer base() const{ return __ptr_; } // explicit

	reference operator*() const {return __ptr_->__value_;}
	pointer operator->() const {return &__ptr_->__value_;}

	tree_iterator& operator++(){
		__ptr_ = static_cast<node_pointer>(tree_next(static_cast<node_base_pointer>(__ptr_)));
		return *this;
	}
	tree_iterator operator++(int){
		tree_iterator t(*this);
		++(*this);
		return t;
	}

	tree_iterator& operator--(){
		__ptr_ = static_cast<node_pointer>(tree_prev(static_cast<node_base_pointer>(__ptr_)))
	;
		return *this;}
	tree_iterator operator--(int){
		tree_iterator t(*this);
		--(*this);
		return t;
	}
};

template <typename T, typename U, typename Ptr1, typename Ptr2>
bool operator==(const tree_iterator<T, Ptr1>& x, const tree_iterator<U, Ptr2>& y){
	return x.base() == y.base();
}
template <typename T, typename U, typename Ptr1, typename Ptr2>
bool operator!=(const tree_iterator<T, Ptr1>& x, const tree_iterator<U, Ptr2>& y){
	return !(x == y);
}

template <typename Tp, typename Compare, typename Allocator>
class tree
{
public:
	typedef Tp                                  value_type;
	typedef Compare                             value_compare;
	typedef Allocator                           allocator_type;
	typedef typename Allocator::size_type       size_type;
	typedef typename Allocator::difference_type difference_type;
	typedef typename Allocator::pointer         pointer;
	typedef typename Allocator::const_pointer   const_pointer;

// CHECK visibility
	typedef tree_node<value_type>                  node;
	typedef typename node::base                    node_base;
	typedef typename Allocator::template
			rebind<node>::other                    node_allocator;
	typedef typename node_allocator::pointer       node_pointer;
	typedef typename node_allocator::const_pointer node_const_pointer;
	typedef typename node_base::pointer            node_base_pointer;
	typedef typename node_base::const_pointer      node_base_const_pointer;

	typedef tree_node_destructor<node_allocator> Dp;
	typedef unique_ptr<node, Dp>                 node_holder;

// public:
	typedef tree_iterator<value_type,
		node_pointer, difference_type>             iterator;
	typedef tree_iterator<const value_type,
		node_const_pointer, difference_type>       const_iterator;

	typedef ::ft::reverse_iterator<iterator>       reverse_iterator;
	typedef ::ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:
	typedef typename node_base::base end_node;
	typedef end_node*                end_node_pointer;
	typedef const end_node*          end_node_const_pointer; // CHECK

	end_node       __end_node_;
	node_pointer   __begin_node_;
	value_compare  __comp_;
	size_type      __size_;
	node_allocator __alloc_;

	node_pointer& __begin_node(){return __begin_node_;}
	const node_pointer& __begin_node() const{return __begin_node_;}

	size_type& size(){return __size_;}

	const node_allocator& __node_alloc() const{return __alloc_;}

public:
	node_pointer __end_node(){
		return static_cast<node_pointer>(addressof(__end_node_));
	}
	node_const_pointer __end_node() const{
		return static_cast<node_const_pointer>(addressof(__end_node_));
	}

	const size_type& size() const{return __size_;}   // map.max_size

	node_allocator& __node_alloc(){return __alloc_;} // assignment operator
	allocator_type __alloc() const{                  // map.get_allocator
		return allocator_type(__node_alloc());
	}

	value_compare& value_comp(){return __comp_;}     // assignment operator
	const value_compare& value_comp() const{return __comp_;} 

	node_pointer __root(){
		return static_cast<node_pointer>(__end_node()->__left_);
	}
	node_const_pointer __root() const{
		return static_cast<node_const_pointer>(__end_node()->__left_);
	}

	explicit tree(const value_compare& __comp);
	explicit tree(const allocator_type& __a);
	tree(const value_compare& __comp, const allocator_type& __a);
	tree(const tree& __t);
	tree& operator=(const tree& __t); //__node_alloc() = __t.__node_alloc()
	template <typename InputIterator>
	void __assign_unique(InputIterator __first, InputIterator __last);

	~tree();

};

template <typename Tp, typename Compare, typename Allocator>
tree<Tp, Compare, Allocator>::tree(const value_compare& __comp)
	: __size_(0), __comp_(__comp)

{
	__begin_node() = __end_node();
}

template <typename Tp, typename Compare, typename Allocator>
tree<Tp, Compare, Allocator>::tree(const allocator_type& __a)
	: __begin_node_(node_pointer()),
	__size_(0),
	__alloc_(node_allocator(__a))
{
	__begin_node() = __end_node();
}

template <typename Tp, typename Compare, typename Allocator>
tree<Tp, Compare, Allocator>::tree(const value_compare& __comp,
										const allocator_type& __a)
	: __begin_node_(node_pointer()),
	__comp_(__comp),
	__size_(0),
	__alloc_(node_allocator(__a))
{
	__begin_node() = __end_node();
}

template <typename Tp, typename Compare, typename Allocator>
tree<Tp, Compare, Allocator>::tree(const tree& __t)
	: __begin_node_(node_pointer()),
	__comp_(__t.value_comp()),
	__size_(0),
	__alloc_(__t.__node_alloc())

{
	__begin_node() = __end_node();
}

template <typename Tp, typename Compare, typename Allocator>
tree<Tp, Compare, Allocator>&
tree<Tp, Compare, Allocator>::operator=(const tree& __t)
{
	if (this != &__t)
	{
		value_comp() = __t.value_comp();
		__alloc() = __t.__alloc();
		__assign_unique(__t.begin(), __t.end());
	}
	return *this;
}

template <typename Tp, typename Compare, typename Allocator>
template <typename InputIterator>
void
tree<Tp, Compare, Allocator>::__assign_unique(InputIterator __first, InputIterator __last)
{
}

template <typename Tp, typename Compare, typename Allocator>
tree<Tp, Compare, Allocator>::~tree()
{
	destroy(__root());
}

}

#endif /* __FT_TREE_H__ */
