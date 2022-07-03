#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <cstddef>
#include "utils.hpp"

namespace ft {

template <typename Iterator>
	class reverse_iterator { 

		public:

			typedef Iterator													iterator_type;
			
			typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type        value_type;
			typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
			typedef typename iterator_traits<iterator_type>::pointer           pointer;
			typedef typename iterator_traits<iterator_type>::reference         reference;


			reverse_iterator() : m_ptr() { };
			
			reverse_iterator(const iterator_type cpy) : m_ptr(cpy)  {};

			template <typename T>
			reverse_iterator(const reverse_iterator<T>& cpy) : m_ptr(cpy.base())  {};

			virtual ~reverse_iterator() {};

			template <typename T>
			reverse_iterator &operator=( const reverse_iterator<T> &rhs) { m_ptr = rhs.base(); return *this; };

			iterator_type base() const { return m_ptr; };

			reverse_iterator& operator++() { --m_ptr; return *this; };

			reverse_iterator operator++(int) { reverse_iterator tmp = *this; --m_ptr; return tmp; };
			
			reverse_iterator& operator--() { ++m_ptr; return *this; };
			reverse_iterator operator--(int) { reverse_iterator tmp = *this; ++m_ptr; return tmp; };
			
			reverse_iterator operator+=(int nb) { m_ptr -= nb; return *this; };
			reverse_iterator operator-=(int nb) { m_ptr += nb; return *this; };
			
			reverse_iterator operator+(int nb) const { reverse_iterator tmp(*this); return tmp.m_ptr -= nb; };

			reverse_iterator operator-(int nb) const { reverse_iterator tmp(*this); return tmp.m_ptr += nb; };

			template <class T>
			difference_type operator-(reverse_iterator<T> &it) { return (it.base().operator-(m_ptr)); };

			reference operator[] (size_t n) const { return *(*this + n); };

			template <class T>
			bool operator<(const reverse_iterator<T>& rhs)  const { return m_ptr > rhs.base(); };			
			
			template <class T>
			bool operator>(const reverse_iterator<T>& rhs)  const { return m_ptr < rhs.base(); };			
			
			template <class T>
			bool operator<=(const reverse_iterator<T>& rhs) const  { return m_ptr >= rhs.base(); };			
			
			template <class T>
			bool operator>=(const reverse_iterator<T>& rhs) const  { return m_ptr <= rhs.base(); };			
			
			template <class T>
			bool operator==(const reverse_iterator<T>& rhs) const  { return m_ptr == rhs.base(); };
			
			template <class T>
			bool operator!=(const reverse_iterator<T>& rhs) const  { return m_ptr != rhs.base();};			
		
			reference operator*() const { iterator_type tmp = m_ptr ; return *--tmp; };
			pointer operator->() const { iterator_type tmp = m_ptr ; return &*--tmp; };

			friend reverse_iterator operator+(difference_type nb, reverse_iterator &it) { return (it += nb); }

			friend reverse_iterator operator-(int nb, reverse_iterator it) { return (it -= nb); }
			
			iterator_type m_ptr;
	};
}

#endif