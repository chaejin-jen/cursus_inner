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

}

#endif /* __FT_TREE_H__ */
