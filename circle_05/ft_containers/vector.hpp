#pragma once
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <memory>
#include <algorithm>
#include <stdexcept>

namespace ft {
template <typename T, typename Allocator = ::std::allocator<T> >
class vector
{
public:
	// types:
	typedef typename Allocator::reference reference; // typedef value_type& reference;
	typedef typename Allocator::const_reference const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type; // Difference between two pointers
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef pointer iterator;                 //typedef value_type* iterator;
	typedef const pointer const_iterator;     //typedef const value_type* const_iterator;
	typedef ::std::reverse_iterator<iterator> reverse_iterator;
	typedef ::std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef ::std::allocator_traits<allocator_type> alloc_traits;


	// construct/copy/destroy:
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
	size_type size() const;
	size_type max_size() const;
	void resize(size_type sz, T c = T());
	size_type capacity() const;
	bool empty() const;
	void reserve(size_type n);

	// element access:
	reference operator[](size_type n);
	const_reference operator[](size_type n) const;
	const_reference at(size_type n) const;
	reference at(size_type n);
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	// modifiers:
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

protected:
	allocator_type alloc_;
	iterator start_;
	iterator finish_;
	iterator end_of_storage_;

private:
	void create();
	void create(size_type n, const T& value);
	void create(const_iterator first, const_iterator last);
	void allocate(size_type n);
	void construct(size_type n, const T& value);
	void construct(const_iterator first, const_iterator last);
	void destroy();

};

//// operator:
//template <typename T, typename Allocator>
//bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
//{
//}

//template <typename T, typename Allocator>
//bool operator< (const vector<T, Allocator>& x, const vector<T, Allocator>& y)
//{

//}

//template <typename T, typename Allocator>
//bool operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
//{

//}

//template <typename T, typename Allocator>
//bool operator> (const vector<T, Allocator>& x, const vector<T, Allocator>& y)
//{

//}

//template <typename T, typename Allocator>
//bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
//{

//}

//template <typename T, typename Allocator>
//bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
//{

//}

//// specialized algorithms:
//template <typename T, typename Allocator>
//void swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
//{

//}


// construct/copy/destroy:
template <typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator &){ create(); }

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type n, const T& value, const Allocator &)
{ create(n, value); }

template <typename T, typename Allocator>
template <typename InputIterator>
vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator &)
{ create(first, last); }

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector<T, Allocator>& x)
{ create(x.begin(), x.end()); }

template <typename T, typename Allocator>
vector<T, Allocator>::~vector(){ destroy(); }

template <typename T, typename Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(const vector<T, Allocator>& x)
{
	if (&x != this) {
		destroy();
		create(x.begin(), x.end());
	}
	return *this;
}

//template <typename T, typename Allocator>
//template <typename InputIterator>
//void vector<T, Allocator>::assign(InputIterator first, InputIterator last)
//{
//	//erase(begin(), end());
//	//insert(begin(), first, last)
//}

//template <typename T, typename Allocator>
//void vector<T, Allocator>::assign(size_type n, const T& u)
//{
//	//erase(begin(), end());
//	//insert(begin(), n, t);
//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::allocator_type
//vector<T, Allocator>::get_allocator() const
//{

//}

// iterators:
template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::begin()
{
	return start_;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::begin() const
{
	return static_cast<vector::const_iterator>(start_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::end()
{
	return finish_;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::end() const
{
	return static_cast<vector::const_iterator>(finish_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rbegin()
{
	return static_cast<vector::reverse_iterator>(finish_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rbegin() const
{
	return static_cast<vector::const_reverse_iterator>(finish_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rend()
{
	return static_cast<vector::reverse_iterator>(start_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rend() const
{
	return static_cast<vector::const_reverse_iterator>(start_);
}

//// capacity:
//template <typename T, typename Allocator>
//typename vector<T, Allocator>::size_type
//vector<T, Allocator>::size() const
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::size_type
//vector<T, Allocator>::max_size() const
//{
	
//}

//template <typename T, typename Allocator>
//void vector<T, Allocator>::resize(size_type sz, T c)
//{
//	if (sz > size())
//		insert(end(), sz - size(), c);
//	else if (sz < size())
//		erase(begin() + sz, end());
//	else
//		;
//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::size_type
//vector<T, Allocator>::capacity() const
//{

//}

//template <typename T, typename Allocator>
//bool vector<T, Allocator>::empty() const
//{

//}

//template <typename T, typename Allocator>
//void vector<T, Allocator>::reserve(size_type n)
//{
//	if (n > max_size())
//		throw ::std::length_error("over max_size");
//}

//// element access:

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::reference
//vector<T, Allocator>::operator[](size_type n)
//{
//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::const_reference
//vector<T, Allocator>::operator[](size_type n) const
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::const_reference
//vector<T, Allocator>::at(size_type n) const
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::reference
//vector<T, Allocator>::at(size_type n)
//{
//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::reference
//vector<T, Allocator>::front()
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::const_reference
//vector<T, Allocator>::front() const
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::reference
//vector<T, Allocator>::back()
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::const_reference
//vector<T, Allocator>::back() const
//{

//}

//// modifiers:

//template <typename T, typename Allocator>
//void vector<T, Allocator>::push_back(const T& x)
//{

//}

//template <typename T, typename Allocator>
//void vector<T, Allocator>::pop_back()
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::iterator
//vector<T, Allocator>::insert(iterator position, const T& x)
//{

//}

//template <typename T, typename Allocator>
//void vector<T, Allocator>::insert(iterator position, size_type n, const T& x)
//{

//}

//template <typename T, typename Allocator>
//template <typename InputIterator>
//void vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last)
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::iterator
//vector<T, Allocator>::erase(iterator position)
//{

//}

//template <typename T, typename Allocator>
//typename vector<T, Allocator>::iterator
//vector<T, Allocator>::erase(iterator first, iterator last)
//{
//	//throws : Nothing unless an exception is thrown by the copy constructor or assignment operator of T.
//}

//template <typename T, typename Allocator>
//void vector<T, Allocator>::swap(vector<T, Allocator>&)
//{

//}

template <typename T, typename Allocator>
void vector<T, Allocator>::clear(){ destroy(); }

// internal:

template <typename T, typename Allocator>
void vector<T, Allocator>::create()
{
	start_ = finish_ = end_of_storage_ = 0;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::create(size_type n, const T& value)
{
	allocate(n);
	construct(n, value); //__construct_at_end(n);
	//::std::memset(finish_, 0, n * sizeof(T));
}

template <typename T, typename Allocator>
void vector<T, Allocator>::create(const_iterator first, const_iterator last)
{
	allocate(last - first);
	construct(first, last);
}


template <typename T, typename Allocator>
void vector<T, Allocator>::allocate(size_type n)
{
	if (n > max_size())
		throw ::std::length_error("over max_size");
	start_ = finish_ = alloc_.allocate(n);
	end_of_storage_ = start_ + n;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::construct(size_type n, const T& value)
{
	if (n > max_size())
		throw ::std::length_error("over max_size");
	do{
		alloc_.construct(finish_, value);
		++finish_;
		--n;
	}while (n > 0);
}

template <typename T, typename Allocator>
void vector<T, Allocator>::construct(const_iterator first, const_iterator last)
{
	size_t i(0);

	if (first > last)
		return ; // exception
	do{
		alloc_.construct(finish_, *(first + i));
		++finish_;
		++i;
	}while ((first + i) != last);
}

template <typename T, typename Allocator>
void vector<T, Allocator>::destroy()
{
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

}
#endif /* __VECTOR_H__ */
