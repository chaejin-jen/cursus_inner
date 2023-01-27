#pragma once
#ifndef __VECTOR_H__
#define __VECTOR_H__

/*
	vector synopsis
namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
	typedef typename Allocator::reference                  reference;
	typedef typename Allocator::const_reference            const_reference;
	typedef implementation-defined                         iterator;
	typedef implementation-defined                         const_iterator;
	typedef T                                              value_type;
	typedef Allocator                                      allocator_type;
	typedef size_t                                         size_type;
	typedef ft::iterator_traits<iterator>::difference_type difference_type;
	typedef typename Allocator::pointer                    pointer;
	typedef typename Allocator::const_pointer              const_pointer;
	typedef ft::reverse_iterator<iterator>                 reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>           const_reverse_iterator;

	explicit vector(const Allocator & = Allocator());
	explicit vector(size_type n, const T& value = T(),
		const Allocator & = Allocator());
	template <typename InputIterator>
	vector(InputIterator first, InputIterator last,
		const Allocator & = Allocator());
	vector(const vector<T, Allocator>& x);
	~vector();
	vector<T, Allocator>& operator=(const vector<T, Allocator>& x);
	template <typename InputIterator>
	void assign(InputIterator first, InputIterator last);
	void assign(size_type n, const T& u);
	allocator_type get_allocator() const;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	size_type size() const;
	size_type max_size() const;
	void resize(size_type sz, T c = T());
	size_type capacity() const;
	bool empty() const;
	void reserve(size_type n);

	reference operator[](size_type n);
	const_reference operator[](size_type n) const;
	const_reference at(size_type n) const;
	reference at(size_type n);
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	void push_back(const T& x);
	void pop_back();
	iterator insert(iterator position, const T& x);
	void insert(iterator position, size_type n, const T& x);
	template <typename InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(vector<T, Allocator>&);
	void clear();
};

template <typename T, typename Allocator>
bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator< (const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator> (const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y);


template <typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator &);

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type n, const T& value, const Allocator &);

template <typename T, typename Allocator>
template <typename InputIterator>
vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator &);

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector<T, Allocator>& x);

template <typename T, typename Allocator>
vector<T, Allocator>::~vector();

template <typename T, typename Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(const vector<T, Allocator>& x);

template <typename T, typename Allocator>
template <typename InputIterator>
void vector<T, Allocator>::assign(InputIterator first, InputIterator last);

template <typename T, typename Allocator>
void vector<T, Allocator>::assign(size_type n, const T& u);

template <typename T, typename Allocator>
typename vector<T, Allocator>::allocator_type
vector<T, Allocator>::get_allocator() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::begin();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::begin() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::end();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::end() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rbegin();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rbegin() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rend();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rend() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::size() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::max_size() const;

template <typename T, typename Allocator>
void vector<T, Allocator>::resize(size_type sz, T c);

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::capacity() const;

template <typename T, typename Allocator>
bool vector<T, Allocator>::empty() const;

template <typename T, typename Allocator>
void vector<T, Allocator>::reserve(size_type n);

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::operator[](size_type n);

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::operator[](size_type n) const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::at(size_type n) const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::at(size_type n);

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::front();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::front() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::back();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::back() const;

template <typename T, typename Allocator>
void vector<T, Allocator>::push_back(const T& x);

template <typename T, typename Allocator>
void vector<T, Allocator>::pop_back();

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::insert(iterator position, const T& x);

template <typename T, typename Allocator>
void vector<T, Allocator>::insert(iterator position, size_type n, const T& x);

template <typename T, typename Allocator>
template <typename InputIterator>
void vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last);

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(iterator position);

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(iterator first, iterator last);

template <typename T, typename Allocator>
void vector<T, Allocator>::swap(vector<T, Allocator>&);

template <typename T, typename Allocator>
void vector<T, Allocator>::clear();

}
*/

#include <memory>
#include <algorithm>
#include <stdexcept>
#include "ft_iterator.hpp"

namespace ft {
template <typename T, typename Allocator = ::std::allocator<T> >
class vector
{
public:
	// types:
	typedef typename Allocator::reference reference; // typedef value_type& reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef pointer iterator;
	typedef const_pointer const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename ft::iterator_traits<iterator>::difference_type difference_type; // Difference between two pointers
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	// construct/copy/destroy:
	explicit vector(const Allocator & = Allocator()){
		create();
	}
	explicit vector(size_type n, const T& value = T(),
		const Allocator & = Allocator()) {
			create(n, value);
		}
	template <typename InputIterator>
	vector(InputIterator first, InputIterator last,
		const Allocator & = Allocator()) {
			create(first, last);
		}
	vector(const vector<T, Allocator>& x) {
			create(x.begin(), x.end());
		}
	~vector() {
		destroy();
	}
	vector<T, Allocator>& operator=(const vector<T, Allocator>& x){
		if (&x != this) {
			destroy();
			create(x.begin(), x.end());
		}
		return *this;
	}
	template <typename InputIterator>
	void assign(InputIterator first, InputIterator last){
		//erase(begin(), end());
		//insert(begin(), first, last)
	}
	void assign(size_type n, const T& u);
	allocator_type get_allocator() const{
		//erase(begin(), end());
		//insert(begin(), n, t);
	}

	// iterators:
	iterator begin(){
		return iterator(start_);
	}
	const_iterator begin() const{
		return const_iterator(start_);
	}
	iterator end(){
		return iterator(finish_);
	}
	const_iterator end() const{
		return const_iterator(finish_);
	}
	reverse_iterator rbegin(){
		return reverse_iterator(finish_);
	}
	const_reverse_iterator rbegin() const{
		return const_reverse_iterator(finish_);
	}
	reverse_iterator rend(){
		return reverse_iterator(start_);
	}
	const_reverse_iterator rend() const{
		return const_reverse_iterator(start_);
	}

	// capacity:
	size_type size() const{
		return static_cast<size_type>(end() - begin());
	}
	size_type max_size() const{
		return size_type(-1) / sizeof(T);
	}
	void resize(size_type sz, T c = T()){
		//if (sz > size())
		//	insert(end(), sz - size(), c);
		//else if (sz < size())
		//	erase(begin() + sz, end());
		//else
		//	;
	}
	size_type capacity() const{
		return size_type(end_of_storage_ - begin());
	}
	bool empty() const{
		return begin() == end();
	}
	void reserve(size_type n){
		if (n > max_size())
			throw ::std::length_error("over max_size");
		if (capacity() < n)
		{
			const size_type old_size = size();
			allocator_type new_alloc;
			iterator new_iter = new_alloc.allocate(n);
			::std::swap(alloc_, new_alloc);
			::std::swap(start_, new_iter);
			finish_ = start_;
			construct(new_iter, new_iter + old_size);
			destroy();
			::std::swap(alloc_, new_alloc);
			::std::swap(start_, new_iter);
			finish_ = start_ + old_size;
			end_of_storage_ = start_ + n;
		}
	}

	// element access:
	reference operator[](size_type n){

	}
	const_reference operator[](size_type n) const{

	}
	const_reference at(size_type n) const{

	}
	reference at(size_type n){

	}
	reference front(){

	}
	const_reference front() const{

	}
	reference back(){

	}
	const_reference back() const{

	}

	// modifiers:
	void push_back(const T& x){

	}
	void pop_back(){

	}
	iterator insert(iterator position, const T& x){

	}
	void insert(iterator position, size_type n, const T& x){

	}
	template <typename InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last){

	}
	iterator erase(iterator position){

	}
	iterator erase(iterator first, iterator last){
		//throws : Nothing unless an exception is thrown by the copy constructor or assignment operator of T.
	}
	void swap(vector<T, Allocator>& x){
		allocator_type alloc(alloc_);
		iterator start(start_);
		iterator finish(finish_);
		iterator end_of_storage(end_of_storage_);
		alloc_ = x.alloc_;
		start_ = x.start_;
		finish_ = x.finish_;
		end_of_storage_ = x.end_of_storage_;
		x.alloc_ = alloc;
		x.start_ = start;
		x.finish_ = finish;
		x.end_of_storage_ = end_of_storage;
	}
	void clear(){
		destroy();
	}

protected:
	allocator_type alloc_;
	pointer start_;
	pointer finish_;
	pointer end_of_storage_;

private:
	void create(){
		start_ = finish_ = end_of_storage_ = 0;
	}
	void create(size_type n, const T& value){
		if (n > max_size())
			throw ::std::length_error("over max_size");
		start_ = finish_ = alloc_.allocate(n);
		end_of_storage_ = start_ + n;
		construct(n, value);
	}
	void create(const_iterator first, const_iterator last){
		if (last - first > max_size())
			throw ::std::length_error("over max_size");
		start_ = finish_ = alloc_.allocate(last - first);
		end_of_storage_ = start_ + (last - first);
		construct(first, last);
	}

	void construct(size_type n, const T& value){
		if (n > max_size())
			throw ::std::length_error("over max_size");
		do{
			alloc_.construct(finish_, value);
			++finish_;
			--n;
		}while (n > 0);
	}
	void construct(const_iterator first, const_iterator last){
		size_t i(0);

		if (first > last)
			return ; // exception
		do{
			alloc_.construct(finish_, *(first + i));
			++finish_;
			++i;
		}while ((first + i) != last);
	}
	void destroy(){
			if (start_)
		{
			vector::iterator it = finish_;
			while (it != start_) {
				alloc_.destroy(--it);
			}
			alloc_.deallocate(start_, end_of_storage_ - start_);
		}
		start_ = finish_ = end_of_storage_ = 0;
	}

};

//// operator:
//template <typename T, typename Allocator>
//bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y){
//}

//template <typename T, typename Allocator>
//bool operator< (const vector<T, Allocator>& x, const vector<T, Allocator>& y){

//}

//template <typename T, typename Allocator>
//bool operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y){

//}

//template <typename T, typename Allocator>
//bool operator> (const vector<T, Allocator>& x, const vector<T, Allocator>& y){

//}

//template <typename T, typename Allocator>
//bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y){

//}

//template <typename T, typename Allocator>
//bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y){

//}

// specialized algorithms:
template <typename T, typename Allocator>
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
{
	x.swap(y);
}

}

#endif /* __VECTOR_H__ */
