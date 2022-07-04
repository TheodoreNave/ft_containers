#ifndef ITERATORS_VECTOR_HPP
#define ITERATORS_VECTOR_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <cstddef>

#include "utils.hpp"

namespace ft {


	/* ************************************************************************** */
	/*                         Iterator / Const Iterator: :                       */
	/* ************************************************************************** */

	template<class T, bool _const = false>
	class iterator_vector { 

		public:
			
			typedef T													value_type;
			typedef ptrdiff_t											difference_type;
			typedef typename check_const<_const, const T&, T&>::type	reference;
			typedef typename check_const<_const, const T*, T*>::type	pointer;
			typedef size_t												size_type;
    		typedef std::bidirectional_iterator_tag 					iterator_category;


			iterator_vector<T, _const>() : m_ptr(NULL) { };

			iterator_vector<T, _const>(value_type *ptr) : m_ptr(ptr) { };

			iterator_vector<T, _const>(const iterator_vector<T, false>& cpy) { 
				
				m_ptr = cpy.m_ptr; 
			};

			virtual ~iterator_vector<T, _const>() { };

			iterator_vector<T, _const> &operator=( const iterator_vector<T, _const> &rhs) {
				
				m_ptr = rhs.m_ptr; 
				return *this; 
			};

			iterator_vector<T, _const>& operator++() { 
				
				m_ptr++; 
				return *this; 
			};

			iterator_vector<T, _const> operator++(int) { 
				
				iterator_vector<T, _const> tmp = *this; 
				++(*this); 
				return tmp; 
			};
			
			iterator_vector<T, _const>& operator--() {
				
				m_ptr--; 
				return *this; 
			};

			iterator_vector<T, _const> operator--(int) {

				iterator_vector<T, _const> tmp = *this;
				--(*this); 
				return tmp; 
			};
			
			iterator_vector<T, _const> operator+=(int nb) {
				
				m_ptr += nb;
				return *this; 
			};

			iterator_vector<T, _const> operator-=(int nb) {
				
				m_ptr -= nb;
				return *this;
			};
			
			iterator_vector<T, _const> operator+(int nb) { 
				
				iterator_vector<T, _const> tmp(*this);
				return tmp += nb;
			};
			iterator_vector<T, _const> operator-(int nb) { 
				
				iterator_vector<T, _const> tmp(*this);
				return tmp -= nb;
			};

			difference_type operator-(iterator_vector<T, true> it) const { return (this->m_ptr - it.m_ptr); };

			reference operator[] (size_t n) const { return (m_ptr[n]); };

			bool operator<(const iterator_vector<T, true>& rhs) const { return m_ptr < rhs.m_ptr; };			
			bool operator>(const iterator_vector<T, true>& rhs) const { return m_ptr > rhs.m_ptr; };			
			bool operator<=(const iterator_vector<T, true>& rhs) const { return m_ptr <= rhs.m_ptr; };			
			bool operator>=(const iterator_vector<T, true>& rhs) const { return m_ptr >= rhs.m_ptr; };			
			bool operator==(const iterator_vector<T, true>& rhs) const { return m_ptr == rhs.m_ptr; };
			bool operator!=(const iterator_vector<T, true>& rhs) const { return m_ptr != rhs.m_ptr; };			
		
			reference operator*() const { return *m_ptr; };
			pointer operator->() const { return m_ptr; };

			friend iterator_vector<T, _const> operator+(int nb, iterator_vector<T, _const> it) { return (it += nb); }

			friend iterator_vector<T, _const> operator-(int nb, iterator_vector<T, _const> it) { return (it -= nb); }
			
			pointer m_ptr;
	
	};
}

#endif