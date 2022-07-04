#ifndef ITERATOR_SET_HPP
#define ITERATOR_SET_HPP

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
	struct RB_Tree_two {

		T _pair;
		RB_Tree_two *left;
		RB_Tree_two *right;
		RB_Tree_two *parent;
		RB_Tree_two **tNULL;
		RB_Tree_two **root;
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

	template<class key, bool isConst = false>
	class iterator_set {

		public:
			
			typedef iterator_set<key, isConst> 																		Self;
    		typedef key																		value_type;
			typedef ptrdiff_t																							difference_type;
			typedef std::bidirectional_iterator_tag 																	iterator_category;
			
			typedef typename check_const_map<isConst, const value_type&, value_type&>::type								reference;
			typedef typename check_const_map<isConst, const value_type*, value_type*>::type								pointer;
			typedef typename check_const_map<isConst, const RB_Tree_two<value_type>*, RB_Tree_two<value_type>* >::type			_Node;

			iterator_set(void) : _pNode(NULL) { };
		
			iterator_set(_Node n) :_pNode(n) { };

			iterator_set(const iterator_set<key, false> &copy) : _pNode(copy._pNode) { };
			iterator_set(const iterator_set<key, true> &copy) : _pNode(copy._pNode) { };

			virtual ~iterator_set() { };
		
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

				iterator_set res(*this);

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

				iterator_set res(*this);

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