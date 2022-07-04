#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
#define BLACK 0 
#define RED 1

namespace ft {

	template <typename T>
	struct RB_Tree {

		T _pair;
		RB_Tree *left;
		RB_Tree *right;
		RB_Tree *parent;
		RB_Tree **tNULL;
		RB_Tree **root;
		int color;
	};

	template<bool isConst, typename type_const, typename type_normal>
	struct check_const_map;

	template<typename type_const, typename type_normal>
	struct check_const_map<true, type_const, type_normal> {

		typedef type_const type;
	};

	template<typename type_const, typename type_normal>
	struct check_const_map<false, type_const, type_normal> {

		typedef type_normal type;
	};

	template<class key, class T, bool isConst = false>
	class iterator_map {

		public:
			
			typedef iterator_map<key, T, isConst> 																		Self;
    		typedef ft::pair<const key, T>																				value_type;
			typedef ptrdiff_t																							difference_type;
			typedef std::bidirectional_iterator_tag 																	iterator_category;
			
			typedef typename check_const_map<isConst, const value_type&, value_type&>::type								reference;
			typedef typename check_const_map<isConst, const value_type*, value_type*>::type								pointer;
			typedef typename check_const_map<isConst, const RB_Tree<value_type>*, RB_Tree<value_type>* >::type			_Node;

			iterator_map(void) : _pNode(NULL) { };
		
			iterator_map(_Node n) :_pNode(n) { };

			iterator_map(const iterator_map<key, T, false> &copy) : _pNode(copy._pNode) { };
			iterator_map(const iterator_map<key, T, true> &copy) : _pNode(copy._pNode) { };

			virtual ~iterator_map() { };
		
			Self   &operator = (const Self &rhs) {

				if (&rhs != this)
					_pNode = rhs._pNode;
				return *this;
			};

			reference operator*() const { return _pNode->_pair; }
			
			pointer operator->() const { return &_pNode->_pair; }

			Self& operator++() {

				if (_pNode == maximum(*_pNode->root))
					_pNode = *_pNode->tNULL;
				else
					_pNode = successor(_pNode);
				return *this;
			}

			Self operator++(int) {

				iterator_map res(*this);

				if (_pNode == maximum(*_pNode->root))
					_pNode = *_pNode->tNULL;
				else
					_pNode = successor(_pNode);
				return res;
			}

			Self& operator--() {

				if (_pNode == minimum(*_pNode->root))
					_pNode = *_pNode->tNULL;
				else if (_pNode == *_pNode->tNULL)
					_pNode = maximum(*_pNode->root);
				else
					_pNode = predecessor(_pNode);
				return *this;
			}

			Self operator--(int) {

				iterator_map res(*this);

				if (_pNode == minimum(*_pNode->root))
					_pNode = *_pNode->tNULL;
				else if (_pNode == *_pNode->tNULL)
					_pNode = maximum(*_pNode->root);
				else
					_pNode = predecessor(_pNode);
				return res;
			}

			template <typename T1>
			bool operator==(const T1& s) const {

				return _pNode == s._pNode;
			}

			template <typename T1>
			bool operator!=(const T1& s) const {

				return _pNode != s._pNode;
			}

			_Node minimum(_Node node) {
		
				while (node->left != *_pNode->tNULL)
					node = node->left;
				return node;
			}

			_Node maximum(_Node node)  {
			
				while (node->right != *_pNode->tNULL)
					node = node->right;
				return node;
			}

			_Node predecessor(_Node x) {
				
				if (x->left != *_pNode->tNULL) 
					return maximum(x->left);
				_Node y = x->parent;
				while (y != *_pNode->tNULL && x == y->left) 
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			_Node successor(_Node x) {
				
				if (x->right != *_pNode->tNULL)
					return minimum(x->right);
				_Node y = x->parent;
				while (y != *_pNode->tNULL && x == y->right) 
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			_Node _pNode;

	};

};

#endif