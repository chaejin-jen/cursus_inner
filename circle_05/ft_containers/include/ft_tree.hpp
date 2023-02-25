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
			::ft::destroy(::ft::addressof(__p->__value_));
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

	tree_node_base()
		: __right_(), __parent_(), __is_black_(false) {}
};

template<bool Shared>
struct tree_node_base_selector;

template<>
struct tree_node_base_selector<false> {
	typedef tree_node_base type;
};

template<>
struct tree_node_base_selector<true>{
	typedef const tree_node_base type;
};

template <typename Tp, bool Select = false>
struct tree_node : public tree_node_base{
public:
	typedef typename tree_node_base_selector<Select>::type base;

	typedef Tp value_type;

	value_type __value_;
	explicit tree_node(const value_type& value)
		: __value_(value){};
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
//      case 1 : red uncle
//      case 2 : black uncle(triangle)
//      case 3 : black uncle(line)
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
				x->__is_black_ = x == root;   // grand  r
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
				//case 3
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
				x->__is_black_ = x == root;   // grand  r
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
				//case 3
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


// Effects:  Rebalances after erase z color black. (child x, and sibling w)
// Precondition: x can be NULL, w != NULL
//               if deleted node is black,
//                sibling node w always exist for same number of black nodes.
// case: x starts with black color
//      case 1 : w is red
//      case 2 : w is black, and w.left & w. right are black.
//      case 3 : w is black, and w.left is red and w. right is black.
//      case 4 : w is black, and w.right is red
template <typename NodePtr>
void
tree_balance_after_remove(NodePtr root, NodePtr x, NodePtr w)
{
	while (true)
	{
		if (!tree_is_left_child(w))
		{
			// w == w->__parent_->__right_
			if (!w->__is_black_) // w has children
			{
				// case 1
				w->__is_black_ = true;
				w->__parent_->__is_black_ = false;
				tree_left_rotate(w->__parent_); // w->__right_ will be w->__left_->__right_
				if (root == w->__left_)
					root = w;
				w = w->__left_->__right_;
			}
			if ((w->__left_  == NULL || w->__left_->__is_black_) &&
			(w->__right_ == NULL || w->__right_->__is_black_))
			{
				// case 2
				w->__is_black_ = false;
				x = w->__parent_;
				if (x == root || !x->__is_black_)
				{
					x->__is_black_ = true;
					break;
				}
				w = tree_is_left_child(x) ?
						x->__parent_->__right_ :
						x->__parent_->__left_;
			}
			else // w has a red child
			{
				if (w->__right_ == NULL || w->__right_->__is_black_)
				{
					// case 3
					w->__left_->__is_black_ = true;
					w->__is_black_ = false;
					tree_right_rotate(w);
					w = w->__parent_;
				}
				// case 4
				w->__is_black_ = w->__parent_->__is_black_;
				w->__parent_->__is_black_ = true;
				w->__right_->__is_black_ = true;
				tree_left_rotate(w->__parent_);
				break;
			}
		}
		else{
			if (!w->__is_black_)
			{
				// case 1
				w->__is_black_ = true;
				w->__parent_->__is_black_ = false;
				tree_right_rotate(w->__parent_);
				if (root == w->__right_)
					root = w;
				w = w->__right_->__left_;
			}
			if ((w->__left_  == NULL || w->__left_->__is_black_) &&
			(w->__right_ == NULL || w->__right_->__is_black_))
			{
				// case 2
				w->__is_black_ = false;
				x = w->__parent_;
				if (!x->__is_black_ || x == root)
				{
					x->__is_black_ = true;
					break;
				}
				w = tree_is_left_child(x) ?
						x->__parent_->__right_ :
						x->__parent_->__left_;
			}
			else{
				if (w->__left_ == NULL || w->__left_->__is_black_)
				{
					// case 3
					w->__right_->__is_black_ = true;
					w->__is_black_ = false;
					tree_left_rotate(w);
					w = w->__parent_;
				}
				// case 4
				w->__is_black_ = w->__parent_->__is_black_;
				w->__parent_->__is_black_ = true;
				w->__left_->__is_black_ = true;
				tree_right_rotate(w->__parent_);
				break;
			}
		}
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
	// x priority : left_child, right_child, NULL
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
		if (x == root || (x != NULL && !x->__is_black_))
		// (1) z->right->__is_black == true
		// (2) tree_min(z)->__is_black == true
			x->__is_black_ = true;
		else
			tree_balance_after_remove(root, x, w);
	}
	// There is no need to rebalance if we removed a red, or if we removed the last node.
}

// iterator

template <typename Tp, typename
NodePtr, typename DiffType = ::std::ptrdiff_t>
class tree_iterator
{
	typedef NodePtr                     node_pointer;
	typedef tree_node<Tp,
		is_const<typename remove_pointer<NodePtr>::type>::value>      node;
	typedef typename node::base         node_base;
	typedef node_base*                  node_base_pointer;

	node_pointer __ptr_;

public:
	typedef ::std::bidirectional_iterator_tag iterator_category;
	typedef Tp                         value_type;
	typedef DiffType                   difference_type;
	typedef value_type&                reference;
	typedef value_type*                pointer;

	tree_iterator(){}
	explicit tree_iterator(node_pointer __p) : __ptr_(__p) {}
	template <typename T, typename U, typename V>
	tree_iterator(const tree_iterator<T, U, V>& other)
		: __ptr_(other.base()) {}
	template <typename T, typename U, typename V>
	tree_iterator& operator=(const tree_iterator<T, U, V>& other){
		__ptr_ = other.base();
		return *this;
	}

	node_pointer base() const{ return __ptr_; }
	node_pointer& refbase() { return __ptr_; }

	tree_iterator next() const{
		tree_iterator tmp(__ptr_);
		return ++tmp;
	}

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

private:
	typedef tree_node<value_type>          node;
	typedef typename node::base                    node_base;
	typedef typename Allocator::template
			rebind<node>::other                    node_allocator;
	typedef typename node_allocator::pointer       node_pointer;
	typedef typename node_allocator::const_pointer node_const_pointer;
	typedef typename node_base::pointer            node_base_pointer;
	typedef typename node_base::const_pointer      node_base_const_pointer;

	typedef tree_node_destructor<node_allocator> Dp;
	typedef unique_ptr<node, Dp>                 node_holder;

public:
	typedef tree_iterator<value_type,
		node_pointer, difference_type>             iterator;
	typedef tree_iterator<const value_type,
		node_const_pointer, difference_type>       const_iterator;

	typedef ::ft::reverse_iterator<iterator>       reverse_iterator;
	typedef ::ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:
	typedef typename node_base::base end_node;
	typedef end_node*                end_node_pointer;
	typedef const end_node*          end_node_const_pointer;

	end_node       __end_node_;
	node_pointer   __begin_node_;
	value_compare  __comp_;
	size_type      __size_;
	node_allocator __alloc_;

	node_pointer& __begin_node(){return __begin_node_;}
	const node_pointer& __begin_node() const{return __begin_node_;}

	const node_allocator& __node_alloc() const{return __alloc_;}

	node_pointer __end_node(){
		return static_cast<node_pointer>(::ft::addressof(__end_node_));
	}
	node_const_pointer __end_node() const{
		return static_cast<node_const_pointer>(::ft::addressof(__end_node_));
	}

	size_type& size(){return __size_;}

	node_pointer __root(){
		return static_cast<node_pointer>(__end_node()->__left_);
	}
	node_const_pointer __root() const{
		return static_cast<node_const_pointer>(__end_node()->__left_);
	}

public:
	const size_type& size() const{return __size_;}   // map.max_size

	node_allocator& __node_alloc(){return __alloc_;} // assignment operator
	allocator_type __alloc() const{                  // map.get_allocator
		return allocator_type(__node_alloc());
	}

	value_compare& value_comp(){return __comp_;}     // assignment operator
	const value_compare& value_comp() const{return __comp_;} // map.key_comp

	explicit tree(const value_compare& __comp);
	explicit tree(const allocator_type& __a);
	tree(const value_compare& __comp, const allocator_type& __a);
	tree(const tree& __t);
	tree& operator=(const tree& __t);

	~tree();

	iterator begin(){return iterator(__begin_node());}
	const_iterator begin() const{return const_iterator(__begin_node());}
	iterator end(){return iterator(__end_node());}
	const_iterator end() const{return const_iterator(__end_node());}

	reverse_iterator rbegin(){return reverse_iterator(end());}
	const_reverse_iterator rbegin() const{return const_reverse_iterator(end());}
	reverse_iterator rend(){return reverse_iterator(begin());}
	const_reverse_iterator rend() const{return const_reverse_iterator(begin());}

	size_type max_size() const{
		return __alloc_.max_size();
	}

	void clear();

	void swap(tree& __t);

	pair<iterator, bool> __insert_unique(const value_type& __v);
	iterator __insert_unique(const_iterator __p, const value_type& __v);

	iterator erase(const_iterator __p);
	iterator erase(const_iterator __f, const_iterator __l);
	template <typename Key>
	size_type __erase_unique(const Key& __k);

	void __insert_node_at(node_base_pointer __parent,
						node_base_pointer& __child,
						node_base_pointer __new_node);

	template <typename Key>
	iterator find(const Key& __v);
	template <typename Key>
	const_iterator find(const Key& __v) const;

	template <typename Key>
	size_type __count_unique(const Key& __k) const;

	template <typename Key>
	iterator lower_bound(const Key& __v){
			return __lower_bound(__v, __root(), __end_node());
	}
	template <typename Key>
	iterator __lower_bound(const Key& __v,
							node_pointer root,
							node_pointer __result);
	template <typename Key>
	const_iterator lower_bound(const Key& __v) const{
			return __lower_bound(__v, __root(), __end_node());
	}
	template <typename Key>
	const_iterator __lower_bound(const Key& __v,
									node_const_pointer root,
									node_const_pointer __result) const;
	template <typename Key>
	iterator upper_bound(const Key& __v){
			return __upper_bound(__v, __root(), __end_node());
	}
	template <typename Key>
	iterator __upper_bound(const Key& __v,
							node_pointer root,
							node_pointer __result);
	template <typename Key>
	const_iterator upper_bound(const Key& __v) const{
		return __upper_bound(__v, __root(), __end_node());
	}
	template <typename Key>
	const_iterator __upper_bound(const Key& __v,
								node_const_pointer root,
								node_const_pointer __result) const;
	template <typename Key>
	pair<iterator, iterator>
	__equal_range_unique(const Key& __k);
	template <typename Key>
	pair<const_iterator, const_iterator>
	__equal_range_unique(const Key& __k) const;

private:
	template <typename Key>
		typename node_base::pointer&
		__find_equal(typename node_base::pointer& __parent, const Key& __v);
	template <typename Key>
		typename node_base::pointer&
		__find_equal(const_iterator __hint, typename node_base::pointer& __parent,
					const Key& __v);

	node_holder __construct_node(const value_type& __v);

	void destroy(node_pointer __nd);

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
		clear();
		value_comp() = __t.value_comp();
		__alloc() = __t.__alloc();
		const_iterator first = __t.begin();
		const_iterator last = __t.end();
		for ( ; first != last; ++first)
			__insert_unique(*first);
	}
	return *this;
}

template <typename Tp, typename Compare, typename Allocator>
tree<Tp, Compare, Allocator>::~tree()
{
	destroy(__root());
}

template <typename Tp, typename Compare, typename Allocator>
void
tree<Tp, Compare, Allocator>::destroy(node_pointer __nd)
{
	if (__nd != NULL)
	{
		destroy(static_cast<node_pointer>(__nd->__left_));
		destroy(static_cast<node_pointer>(__nd->__right_));
		node_allocator& __na = __node_alloc();
		::ft::destroy(::ft::addressof(__nd->__value_));
		__na.deallocate(__nd, 1);
	}
}

template <typename Tp, typename Compare, typename Allocator>
void
tree<Tp, Compare, Allocator>::swap(tree& __t){
	::std::swap(__begin_node_, __t.__begin_node_);
	::std::swap(__end_node_, __t.__end_node_);
	::std::swap(__node_alloc(), __t.__node_alloc());
	::std::swap(__size_, __t.__size_);
	::std::swap(__comp_, __t.__comp_);
	if (size() == 0)
		__begin_node() = __end_node();
	else
		__end_node()->__left_->__parent_ = __end_node();
	if (__t.size() == 0)
		__t.__begin_node() = __t.__end_node();
	else
		__t.__end_node()->__left_->__parent_ = __t.__end_node();
}

template <typename Tp, typename Compare, typename Allocator>
void
tree<Tp, Compare, Allocator>::clear()
{
	destroy(__root());
	size() = 0;
	__begin_node() = __end_node();
	__end_node()->__left_ = NULL;
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::node_base::pointer&
tree<Tp, Compare, Allocator>::__find_equal(typename node_base::pointer& __parent,
												const Key& __v)
{
	node_pointer __nd = __root();
	if (__nd != NULL)
	{
		while (true)
		{
			if (value_comp()(__v, __nd->__value_))
			{
				if (__nd->__left_ != NULL)
					__nd = static_cast<node_pointer>(__nd->__left_);
				else
				{
					__parent = __nd;
					return __parent->__left_;
				}
			}
			else if (value_comp()(__nd->__value_, __v))
			{
				if (__nd->__right_ != NULL)
					__nd = static_cast<node_pointer>(__nd->__right_);
				else
				{
					__parent = __nd;
					return __parent->__right_;
				}
			}
			else
			{
				__parent = __nd;
				return __parent;
			}
		}
	}
	__parent = __end_node();
	return __parent->__left_;
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::node_base::pointer&
tree<Tp, Compare, Allocator>::__find_equal(const_iterator __hint,
												typename node_base::pointer& __parent,
												const Key& __v)
{
	if (__hint == end() || value_comp()(__v, *__hint))  // check before
	{
		// __v < *__hint
		const_iterator __prior = __hint;
		if (__prior == begin() || value_comp()(*--__prior, __v))
		{
			// *prev(__hint) < __v < *__hint
			if (__hint.base()->__left_ == NULL)
			{
				__parent = const_cast<node_pointer&>(__hint.refbase());
				return __parent->__left_;
			}
			else
			{
				__parent = const_cast<node_pointer&>(__prior.refbase());
				return __parent->__right_;
			}
		}
		// __v <= *prev(__hint)
		return __find_equal(__parent, __v);
	}
	else if (value_comp()(*__hint, __v))  // check after
	{
		// *__hint < __v
		const_iterator __next = __hint.next();
		if (__next == end() || value_comp()(__v, *__next))
		{
			// *__hint < __v < *next(__hint)
			if (__hint.base()->__right_ == NULL)
			{
				__parent = const_cast<node_pointer&>(__hint.refbase());
				return __parent->__right_;
			}
			else
			{
				__parent = const_cast<node_pointer&>(__next.refbase());
				return __parent->__left_;
			}
		}
		// *next(__hint) <= __v
		return __find_equal(__parent, __v);
	}
	// else __v == *__hint
	__parent = const_cast<node_pointer&>(__hint.refbase());
	return __parent;
}

template <typename Tp, typename Compare, typename Allocator>
void
tree<Tp, Compare, Allocator>::__insert_node_at(node_base_pointer __parent,
													node_base_pointer& __child,
													node_base_pointer __new_node)
{
	__new_node->__left_   = NULL;
	__new_node->__right_  = NULL;
	__new_node->__parent_ = __parent;
	__child = __new_node;
	if (__begin_node()->__left_ != NULL)
		__begin_node() = static_cast<node_pointer>(__begin_node()->__left_);
	tree_balance_after_insert(__end_node()->__left_, __child);
	++size();
}

template <typename Tp, typename Compare, typename Allocator>
typename tree<Tp, Compare, Allocator>::node_holder
tree<Tp, Compare, Allocator>::__construct_node(const value_type& __v)
{
	node_allocator& __na = __node_alloc();
	node_holder __h(__na.allocate(1), Dp(__na));
	::ft::construct(::ft::addressof(__h->__value_), __v);
	__h.get_deleter().__value_constructed = true;
	return __h;
}

template <typename Tp, typename Compare, typename Allocator>
pair<typename tree<Tp, Compare, Allocator>::iterator, bool>
tree<Tp, Compare, Allocator>::__insert_unique(const value_type& __v)
{
	node_base_pointer __parent;
	node_base_pointer& __child = __find_equal(__parent, __v);
	node_pointer __r = static_cast<node_pointer>(__child);
	bool __inserted = false;
	if (__child == NULL)
	{
		node_holder __h = __construct_node(__v);
		__insert_node_at(__parent, __child, __h.get());
		__r = __h.release();
		__inserted = true;
	}
	return pair<iterator, bool>(iterator(__r), __inserted);
}

template <typename Tp, typename Compare, typename Allocator>
typename tree<Tp, Compare, Allocator>::iterator
tree<Tp, Compare, Allocator>::__insert_unique(const_iterator __p, const value_type& __v)
{
	node_base_pointer __parent;
	node_base_pointer& __child = __find_equal(__p, __parent, __v);
	node_pointer __r = static_cast<node_pointer>(__child);
	if (__child == NULL)
	{
		node_holder __h = __construct_node(__v);
		__insert_node_at(__parent, __child, __h.get());
		__r = __h.release();
	}
	return iterator(__r);
}

template <typename Tp, typename Compare, typename Allocator>
typename tree<Tp, Compare, Allocator>::iterator
tree<Tp, Compare, Allocator>::erase(const_iterator __p)
{
	node_pointer __np = const_cast<node_pointer>(__p.base());
	iterator __r(__np);
	++__r;
	if (__begin_node() == __np)
		__begin_node() = __r.base();
	--size();
	node_allocator& __na = __node_alloc();
	::ft::destroy(const_cast<value_type*>(::ft::addressof(*__p)));
	tree_remove(__end_node()->__left_,
				static_cast<node_base_pointer>(__np));
	__na.deallocate(__np, 1);
	return __r;
}

template <typename Tp, typename Compare, typename Allocator>
typename tree<Tp, Compare, Allocator>::iterator
tree<Tp, Compare, Allocator>::erase(const_iterator __f, const_iterator __l)
{
	while (__f != __l)
		__f = erase(__f);
	return iterator(const_cast<node_pointer>(__l.base()));
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::size_type
tree<Tp, Compare, Allocator>::__erase_unique(const Key& __k)
{
	iterator __i = find(__k);
	if (__i == end())
		return 0;
	erase(__i);
	return 1;
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::iterator
tree<Tp, Compare, Allocator>::find(const Key& __v)
{
	iterator __p = __lower_bound(__v, __root(), __end_node());
	if (__p != end() && !value_comp()(__v, *__p))
		return __p;
	return end();
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::const_iterator
tree<Tp, Compare, Allocator>::find(const Key& __v) const
{
	const_iterator __p = __lower_bound(__v, __root(), __end_node());
	if (__p != end() && !value_comp()(__v, *__p))
		return __p;
	return end();
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::size_type
tree<Tp, Compare, Allocator>::__count_unique(const Key& __k) const
{
	node_const_pointer __result = __end_node();
	node_const_pointer __rt = __root();
	while (__rt != NULL)
	{
		if (value_comp()(__k, __rt->__value_))
		{
			__result = __rt;
			__rt = static_cast<node_const_pointer>(__rt->__left_);
		}
		else if (value_comp()(__rt->__value_, __k))
			__rt = static_cast<node_const_pointer>(__rt->__right_);
		else
			return 1;
	}
	return 0;
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::iterator
tree<Tp, Compare, Allocator>::__lower_bound(const Key& __v,
												node_pointer root,
												node_pointer __result)
{
	while (root != NULL)
	{
		if (!value_comp()(root->__value_, __v))
		{
			__result = root;
			root = static_cast<node_pointer>(root->__left_);
		}
		else
			root = static_cast<node_pointer>(root->__right_);
	}
	return iterator(__result);
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::const_iterator
tree<Tp, Compare, Allocator>::__lower_bound(const Key& __v,
												node_const_pointer root,
												node_const_pointer __result) const
{
	while (root != NULL)
	{
		if (!value_comp()(root->__value_, __v))
		{
			__result = root;
			root = static_cast<node_const_pointer>(root->__left_);
		}
		else
			root = static_cast<node_const_pointer>(root->__right_);
	}
	return const_iterator(__result);
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::iterator
tree<Tp, Compare, Allocator>::__upper_bound(const Key& __v,
												node_pointer root,
												node_pointer __result)
{
	while (root != NULL)
	{
		if (value_comp()(__v, root->__value_))
		{
			__result = root;
			root = static_cast<node_pointer>(root->__left_);
		}
		else
			root = static_cast<node_pointer>(root->__right_);
	}
	return iterator(__result);
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
typename tree<Tp, Compare, Allocator>::const_iterator
tree<Tp, Compare, Allocator>::__upper_bound(const Key& __v,
												node_const_pointer root,
												node_const_pointer __result) const
{
	while (root != NULL)
	{
		if (value_comp()(__v, root->__value_))
		{
			__result = root;
			root = static_cast<node_const_pointer>(root->__left_);
		}
		else
			root = static_cast<node_const_pointer>(root->__right_);
	}
	return const_iterator(__result);
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
pair<typename tree<Tp, Compare, Allocator>::iterator,
	typename tree<Tp, Compare, Allocator>::iterator>
tree<Tp, Compare, Allocator>::__equal_range_unique(const Key& __k)
{
	typedef pair<iterator, iterator> _Pp;
	node_pointer __result = __end_node();
	node_pointer __rt = __root();
	while (__rt != NULL)
	{
		if (value_comp()(__k, __rt->__value_))
		{
			__result = __rt;
			__rt = static_cast<node_pointer>(__rt->__left_);
		}
		else if (value_comp()(__rt->__value_, __k))
			__rt = static_cast<node_pointer>(__rt->__right_);
		else
			return _Pp(iterator(__rt),
					iterator(
						__rt->__right_ != NULL ?
							static_cast<node_pointer>(tree_min(__rt->__right_))
							: __result));
	}
	return _Pp(iterator(__result), iterator(__result));
}

template <typename Tp, typename Compare, typename Allocator>
template <typename Key>
pair<typename tree<Tp, Compare, Allocator>::const_iterator,
	typename tree<Tp, Compare, Allocator>::const_iterator>
tree<Tp, Compare, Allocator>::__equal_range_unique(const Key& __k) const
{
	typedef pair<const_iterator, const_iterator> _Pp;
	node_const_pointer __result = __end_node();
	node_const_pointer __rt = __root();
	while (__rt != NULL)
	{
		if (value_comp()(__k, __rt->__value_))
		{
			__result = __rt;
			__rt = static_cast<node_const_pointer>(__rt->__left_);
		}
		else if (value_comp()(__rt->__value_, __k))
			__rt = static_cast<node_const_pointer>(__rt->__right_);
		else
			return _Pp(const_iterator(__rt),
					const_iterator(
						__rt->__right_ != NULL ?
							static_cast<node_const_pointer>(tree_min(__rt->__right_))
							: __result));
	}
	return _Pp(const_iterator(__result), const_iterator(__result));
}

template <typename Tp, typename Compare, typename Allocator>
void
swap(tree<Tp, Compare, Allocator>& x,
	tree<Tp, Compare, Allocator>& y){
	x.swap(y);
}

}

#endif /* __FT_TREE_H__ */
