#pragma once
#ifndef __SET_H__
#define __SET_H__

/*
	set synopsis
namespace ft {

template <class Key, class Compare = less<Key>,
	class Allocator = allocator<Key> >
class set {
public:
	// types:
	typedef Key key_type;
	typedef Key value_type;
	typedef Compare key_compare;
	typedef Compare value_compare;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef implementation defined iterator; // See 23.1
	typedef implementation defined const_iterator; // See 23.1
	typedef implementation defined size_type; // See 23.1
	typedef implementation defined difference_type;// See 23.1
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> reverse_iterator;

	// 23.3.3.1 construct/copy/destroy:
	explicit set(const Compare& comp = Compare(),
		const Allocator& = Allocator());

	template <class InputIterator>
	set(InputIterator first, InputIterator last,
		const Compare& comp = Compare(), const Allocator& = Allocator());
	set(const set<Key,Compare,Allocator>& x);
	~set();
	set<Key,Compare,Allocator>& operator=
		(const set<Key,Compare,Allocator>& x);
	allocator_type get_allocator() const;

	// iterators:
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rbegin() const;
	reverse_iterator rend();
	reverse_iterator rend() const;

	// capacity:
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	// modifiers:
	pair<iterator, bool> insert(const value_type& x);
	iterator insert(iterator position, const value_type& x);

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last);

	void erase(iterator position);
	size_type erase(const key_type& x);
	void erase(iterator first, iterator last);
	void swap(set<Key,Compare,Allocator>&);
	void clear();

	// observers:
	key_compare key_comp() const;
	value_compare value_comp() const;

	// set operations:
	iterator find(const key_type& x) const;
	size_type count(const key_type& x) const;

	iterator lower_bound(const key_type& x) const;
	iterator upper_bound(const key_type& x) const;
	pair<iterator,iterator> equal_range(const key_type& x) const;
};

template <class Key, class Compare, class Allocator>
bool operator==(const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y);
template <class Key, class Compare, class Allocator>
bool operator< (const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y);
template <class Key, class Compare, class Allocator>
bool operator!=(const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y);
template <class Key, class Compare, class Allocator>
bool operator> (const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y);
template <class Key, class Compare, class Allocator>
bool operator>=(const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y);
template <class Key, class Compare, class Allocator>
bool operator<=(const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y);

// specialized algorithms:
template <class Key, class Compare, class Allocator>
void swap(set<Key,Compare,Allocator>& x,
	set<Key,Compare,Allocator>& y);

}
*/

#include <memory>
#include <functional>
#include "ft_tree.hpp"
#include "ft_utility.hpp"
#include "ft_algorithm.tpp"

namespace ft {


template <class Key, class Compare = ::std::less<Key>,
	class Allocator = ::std::allocator<Key> >
class set {
public:
	// types:
	typedef Key                                 key_type;
	typedef Key                                 value_type;
	typedef Compare                             key_compare;
	typedef Compare                             value_compare;
	typedef Allocator                           allocator_type;
	typedef typename Allocator::reference       reference;
	typedef typename Allocator::const_reference const_reference;

private:
	typedef ::ft::tree<value_type, value_compare, allocator_type> __base;

	__base __tree_;

public:
	typedef typename __base::const_iterator         iterator;
	typedef typename __base::const_iterator         const_iterator;
	typedef typename __base::size_type              size_type;
	typedef typename __base::difference_type        difference_type;
	typedef typename Allocator::pointer             pointer;
	typedef typename Allocator::const_pointer       const_pointer;
	typedef typename __base::const_reverse_iterator reverse_iterator;
	typedef typename __base::const_reverse_iterator const_reverse_iterator;

	// 23.3.3.1 construct/copy/destroy:
	explicit set(const Compare& comp = Compare(),
		const Allocator& alloc = Allocator())
		: __tree_(comp, alloc) {}

	template <class InputIterator>
	set(InputIterator first, InputIterator last,
		const Compare& comp = Compare(), const Allocator& alloc = Allocator())
		: __tree_(comp, alloc) {
			insert(first, last);
		}
	set(const set<Key,Compare,Allocator>& x)
		: __tree_(x.__tree_) {
			insert(x.begin(), x.end());
		}
	~set(){}
	set<Key,Compare,Allocator>& operator=
		(const set<Key,Compare,Allocator>& x){
			__tree_ = x.__tree_;
			return *this;
		}
	allocator_type get_allocator() const{
		return __tree_.__alloc();
	}

	// iterators:
	iterator begin(){
		return __tree_.begin();
	}
	const_iterator begin() const{
		return __tree_.begin();
	}
	iterator end(){
		return __tree_.end();
	}
	const_iterator end() const{
		return __tree_.end();
	}
	reverse_iterator rbegin(){
		return __tree_.rbegin();
	}
	const_reverse_iterator rbegin() const{
		return __tree_.rbegin();
	}
	reverse_iterator rend(){
		return __tree_.rend();
	}
	const_reverse_iterator rend() const{
		return __tree_.rend();
	}

	// capacity:
	bool empty() const{
		return __tree_.size() == 0;
	}
	size_type size() const{
		return __tree_.size();
	}
	size_type max_size() const{
		return __tree_.max_size();
	}

	// modifiers:
	pair<iterator, bool> insert(const value_type& x){
		return __tree_.__insert_unique(x);
	}
	iterator insert(iterator position, const value_type& x){
		return __tree_.__insert_unique(position, x);
	}

	template <class InputIterator>
	void insert(InputIterator first,
		typename enable_if<!is_integral<InputIterator>::value,
			InputIterator>::type last){
				for ( ; first != last; ++first)
					insert(*first);
			}

	void erase(iterator position){
		__tree_.erase(position);
	}
	size_type erase(const key_type& x){
		return __tree_.__erase_unique(x);
	}
	void erase(iterator first, iterator last){
		__tree_.erase(first, last);
	}
	void swap(set<Key,Compare,Allocator>& other){
		__tree_.swap(other.__tree_);
	}
	void clear(){
		__tree_.clear();
	}

	// observers:
	key_compare key_comp() const{
		 return __tree_.value_comp();
	}
	value_compare value_comp() const{
		 return __tree_.value_comp();
	}

	// set operations:
	iterator find(const key_type& x) const{
		return __tree_.find(x);
	}
	size_type count(const key_type& x) const{
		return __tree_.__count_unique(x);
	}

	iterator lower_bound(const key_type& x) const{
		return __tree_.lower_bound(x);
	}
	iterator upper_bound(const key_type& x) const{
		return __tree_.upper_bound(x);
	}
	::ft::pair<iterator,iterator> equal_range(const key_type& x) const{
		return __tree_.__equal_range_unique(x);
	}
};

template <class Key, class Compare, class Allocator>
bool operator==(const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y){
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}
template <class Key, class Compare, class Allocator>
bool operator< (const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y){
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}
template <class Key, class Compare, class Allocator>
bool operator!=(const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y){
		return !(x == y);
	}
template <class Key, class Compare, class Allocator>
bool operator> (const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y){
		return y < x;
	}
template <class Key, class Compare, class Allocator>
bool operator>=(const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y){
		return !(x < y);
	}
template <class Key, class Compare, class Allocator>
bool operator<=(const set<Key,Compare,Allocator>& x,
	const set<Key,Compare,Allocator>& y){
		return !(y < x);
	}

// specialized algorithms:
template <class Key, class Compare, class Allocator>
void swap(set<Key,Compare,Allocator>& x,
	set<Key,Compare,Allocator>& y){
		x.swap(y);
	}

}

#endif /* __SET_H__ */
