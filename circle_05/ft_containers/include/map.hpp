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
#include <functional>
#include "ft_tree.hpp"
#include "ft_utility.hpp"
#include "ft_algorithm.tpp"
#include "ft_type_traits.tpp"

namespace ft {

template <class Key, class Tp, class Compare, bool = is_empty<Compare>::value>
class map_value_compare
	: private Compare
{
	typedef pair<typename ft::remove_const<Key>::type, Tp> Pp;
	typedef pair<const Key, Tp> CP;

public:
	map_value_compare()
		: Compare() {}
	map_value_compare(Compare c)
		: Compare(c) {}

	const Compare& key_comp() const {return *this;}

	bool operator()(const CP& x, const CP& y) const
		{return static_cast<const Compare&>(*this)(x.first, y.first);}
	bool operator()(const CP& x, const Pp& y) const
		{return static_cast<const Compare&>(*this)(x.first, y.first);}
	bool operator()(const CP& x, const Key& y) const
		{return static_cast<const Compare&>(*this)(x.first, y);}
	bool operator()(const Pp& x, const CP& y) const
		{return static_cast<const Compare&>(*this)(x.first, y.first);}
	bool operator()(const Pp& x, const Pp& y) const
		{return static_cast<const Compare&>(*this)(x.first, y.first);}
	bool operator()(const Pp& x, const Key& y) const
		{return static_cast<const Compare&>(*this)(x.first, y);}
	bool operator()(const Key& x, const CP& y) const
		{return static_cast<const Compare&>(*this)(x, y.first);}
	bool operator()(const Key& x, const Pp& y) const
		{return static_cast<const Compare&>(*this)(x, y.first);}
	bool operator()(const Key& x, const Key& y) const
		{return static_cast<const Compare&>(*this)(x, y);}
};

template <class Key, class Tp, class Compare>
class map_value_compare<Key, Tp, Compare, false>
{
	Compare __comp_;

	typedef pair<typename ft::remove_const<Key>::type, Tp> Pp;
	typedef pair<const Key, Tp> CP;

public:
	map_value_compare()
		: __comp_() {}
	map_value_compare(Compare c)
		: __comp_(c) {}

	const Compare& key_comp() const {return __comp_;}

	bool operator()(const CP& x, const CP& y) const
		{return __comp_(x.first, y.first);}
	bool operator()(const CP& x, const Pp& y) const
		{return __comp_(x.first, y.first);}
	bool operator()(const CP& x, const Key& y) const
		{return __comp_(x.first, y);}
	bool operator()(const Pp& x, const CP& y) const
		{return __comp_(x.first, y.first);}
	bool operator()(const Pp& x, const Pp& y) const
		{return __comp_(x.first, y.first);}
	bool operator()(const Pp& x, const Key& y) const
		{return __comp_(x.first, y);}
	bool operator()(const Key& x, const CP& y) const
		{return __comp_(x, y.first);}
	bool operator()(const Key& x, const Pp& y) const
		{return __comp_(x, y.first);}
	bool operator()(const Key& x, const Key& y) const
		{return __comp_(x, y);}
};

template <class Key, class T, class Compare = ::std::less<Key>,
	class Allocator = ::std::allocator<pair<const Key, T> > >
	class map{
public:
	// types:
	typedef Key                                 key_type;
	typedef T                                   mapped_type;
	typedef pair<const key_type, mapped_type>   value_type;
	typedef Compare                             key_compare;
	typedef Allocator                           allocator_type;
	typedef typename Allocator::reference       reference;
	typedef typename Allocator::const_reference const_reference;

private:
	typedef pair<key_type, mapped_type>                      __value_type;
	typedef map_value_compare<key_type, mapped_type,
								key_compare>                 __vc;
	typedef typename Allocator::template
		rebind<__value_type>::other                          __allocator_type;
	typedef ::ft::tree<value_type, __vc, __allocator_type>   __base;

	__base __tree_;

public:
	typedef typename __base::iterator                  iterator;
	typedef typename __base::const_iterator            const_iterator;
	typedef typename __allocator_type::size_type       size_type;
	typedef typename __allocator_type::difference_type difference_type;
	typedef typename __allocator_type::pointer         pointer;
	typedef typename __allocator_type::const_pointer   const_pointer;
	typedef typename __base::reverse_iterator          reverse_iterator;
	typedef typename __base::const_reverse_iterator    const_reverse_iterator;

public:
	class value_compare
	: public ::std::binary_function<value_type, value_type, bool> {
		friend class map;

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
		: __tree_(__vc(comp), alloc) {}
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const Compare& comp = Compare(), const Allocator& alloc= Allocator())
			: __tree_(__vc(comp), alloc){
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

	// 23.3.1.2 element access:
	T& operator[](const key_type& x){
		return (*((insert(ft::make_pair(x, T()))).first)).second;
	}

	// modifiers:
	pair<iterator, bool> insert(const value_type& x){
		return __tree_.__insert_unique(x);
	}
	iterator insert(const_iterator position, const value_type& x){
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
	void swap(map<Key,T,Compare,Allocator>& other){
		__tree_.swap(other.__tree_);
	}
	void clear(){
		__tree_.clear();
	}

	// observers:
	key_compare key_comp() const{
		 return __tree_.value_comp().key_comp();
	}
	value_compare value_comp() const{
		 return value_compare(__tree_.value_comp().key_comp());
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
			return __tree_.__equal_range_unique(x);
		}
	ft::pair<const_iterator, const_iterator>
		equal_range(const key_type& x) const{
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
