#pragma once
#ifndef __MAP_H__
#define __MAP_H__

/*
	map synopsis
namespace ft {

template <class Key, class T, class Compare = less<Key>,
	class Allocator = allocator<pair<const Key, T> > >
	class map{
public:
	// types:
	typedef Key key_type;
	typedef T mapped_type;
	typedef pair<const Key, T> value_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef implementation defined iterator;       // See 23.1
	typedef implementation defined const_iterator; // See 23.1
	typedef implementation defined size_type;      // See 23.1
	typedef implementation defined difference_type;// See 23.1
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	class value_compare
	: public binary_function<value_type, value_type, bool> {
		friend class map;

	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}

	public:
		bool operator()(const value_type& x, const value_type& y) const {
			return comp(x.first, y.first);
		}
	};

	// 23.3.1.1 construct/copy/destroy:
	explicit map(const Compare& comp = Compare(),
		const Allocator& = Allocator());
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const Compare& comp = Compare(), const Allocator& = Allocator());
	map(const map<Key,T,Compare,Allocator>& x);
	~map();
	map<Key,T,Compare,Allocator>&
		operator=(const map<Key,T,Compare,Allocator>& x);
	allocator_type get_allocator() const;

	// iterators:
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	// capacity:
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	// 23.3.1.2 element access:
	T& operator[](const key_type& x);

	// modifiers:
	pair<iterator, bool> insert(const value_type& x);
	iterator insert(iterator position, const value_type& x);
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last);

	void erase(iterator position);
	size_type erase(const key_type& x);
	void erase(iterator first, iterator last);
	void swap(map<Key,T,Compare,Allocator>&);
	void clear();

	// observers:
	key_compare key_comp() const;
	value_compare value_comp() const;

	// 23.3.1.3 map operations:
	iterator find(const key_type& x);
	const_iterator find(const key_type& x) const;
	size_type count(const key_type& x) const;

	iterator lower_bound(const key_type& x);
	const_iterator lower_bound(const key_type& x) const;
	iterator upper_bound(const key_type& x);
	const_iterator upper_bound(const key_type& x) const;

	pair<iterator,iterator>
		equal_range(const key_type& x);
	pair<const_iterator,const_iterator>
		equal_range(const key_type& x) const;
};

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator> (const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y);

// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void swap(map<Key, T, Compare,Allocator>& x,
	map<Key, T, Compare,Allocator>& y);

}
*/

#include <memory>
#include "ft_tree.hpp"
#include "ft_utility.hpp"
#include "ft_algorithm.tpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
	class Allocator = ::std::allocator<pair<const Key, T> > >
	class map{
public:
	// types:
	typedef Key key_type;
	typedef T mapped_type;
	typedef pair<const Key, T> value_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;


private:
	typedef map_value_compare<key_type, mapped_type, key_compare> vc;
	typedef ft:tree<value_type, vc, allocator_type> base;

	base __tree_;

public:
	typedef typename base::iterator              iterator;
	typedef typename base::const_iterator        const_iterator; 
	typedef typename Allocator::size_type        size_type;
	typedef typename Allocator::difference_type  difference_type;
	typedef typename Allocator::pointer          pointer;
	typedef typename Allocator::const_pointer    const_pointer;
	typedef ft::reverse_iterator<iterator>       reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

public:
	class value_compare
	: public std::binary_function<value_type, value_type, bool> {
		friend class map;
		// friend class map<Key, T, Compare, Allocator>;

	protected:
		key_compare comp;
		value_compare(key_compare c) : comp(c) {}

	public:
		bool operator()(const value_type& x, const value_type& y) const {
			return comp(x.first, y.first);
		}
	};

	// 23.3.1.1 construct/copy/destroy:
	explicit map(const Compare& comp = Compare(),
		const Allocator& alloc = Allocator())
		: __tree_(vc(comp), alloc) {}
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const Compare& comp = Compare(), const Allocator& alloc= Allocator())
			: __tree_(vc(comp), alloc){
				insert(first, last);
			}
	map(const map<Key,T,Compare,Allocator>& x)
		: __tree_(x.__tree_){
			insert(x.begin(), x.end());
		}
	~map(){}
	map<Key, T, Compare, Allocator>&
		operator=(const map<Key,T,Compare,Allocator>& x){
			__tree_ = x.__tree_;
			return *this;
		}
	allocator_type get_allocator() const{
		return __tree_.__alloc();
	}

	// iterators:
	iterator begin(){
		return _tree_.begin();
	}
	const_iterator begin() const{
		return _tree_.begin();
	}
	iterator end(){
		return _tree_.end();
	}
	const_iterator end() const{
		return _tree_.end();
	}
	reverse_iterator rbegin(){
		return reverse_iterator(end());
	}
	const_reverse_iterator rbegin() const{
		return reverse_iterator(end());
	}
	reverse_iterator rend(){
		return reverse_iterator(begin());
	}
	const_reverse_iterator rend() const{
		return reverse_iterator(begin());
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

	// 23.3.1.2 element access:
	T& operator[](const key_type& x){
		return (*((insert(ft::make_pair(x, T()))).first)).second
	}

	// modifiers:
	pair<iterator, bool> insert(const value_type& x){
		return __tree_.__insert_unique(x)
	}
	iterator insert(iterator position, const value_type& x){
		return _tree_.__insert_unique(position._i, x);
		
	}
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last){
		for (const_iterator e = cend(); first != last; ++first)
			insert(e._i, *first);
	}

	void erase(iterator position){
		__tree_.erase(position._i);
	}
	size_type erase(const key_type& x){
		return __tree_.__erase_unique(x);
	}
	void erase(iterator first, iterator last){
		__tree_.erase(first._i, last._i);
	}
	void swap(map<Key,T,Compare,Allocator>& other){
		__tree_.swap(other.tree);
	}
	void clear(){
		__tree_.clear();
	}

	// observers:
	key_compare key_comp() const{
		return __tree_.value_comp().key_comp();
		//return __tree_.value_comp();
	}
	value_compare value_comp() const{
		return value_compare(__tree_.value_comp().key_comp());
		//return value_compare(__tree_.value_comp());
	}

	// 23.3.1.3 map operations:
	iterator find(const key_type& x){
		return __tree_.find(x);
	}
	const_iterator find(const key_type& x) const{
		return __tree_.find(x);
	}
	size_type count(const key_type& x) const{
		return __tree_.__count_unique(x);
	}

	iterator lower_bound(const key_type& x){
		return __tree_.lower_bound(x);
	}
	const_iterator lower_bound(const key_type& x) const{
		return __tree_.lower_bound(x);
	}
	iterator upper_bound(const key_type& x){
		return __tree_.upper_bound(x);
	}
	const_iterator upper_bound(const key_type& x) const{
		return __tree_.upper_bound(x);
	}

	ft::pair<iterator, iterator>
		equal_range(const key_type& x){
			//return ft::make_pair(lower_bound(x), upper_bound(x));
			return __tree_.__equal_range_unique(x);
		}
	ft::pair<const_iterator, const_iterator>
		equal_range(const key_type& x) const{
			//return ft::make_pair(lower_bound(x), upper_bound(x));
			return  __tree_.__equal_range_unique(x);
		}
};

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y){
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}
template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y){
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y){
		return !(x == y);
	}
template <class Key, class T, class Compare, class Allocator>
bool operator> (const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y){
		return y < x;
	}
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y){
		return !(x < y);
	}
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare,Allocator>& x,
	const map<Key, T, Compare,Allocator>& y){
		return !(y < x);
	}

// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void swap(map<Key, T, Compare,Allocator>& x,
	map<Key, T, Compare,Allocator>& y){
		x.swap(y);
	}

}

#endif /* __MAP_H__ */
