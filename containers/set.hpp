#ifndef SET_HPP
#define SET_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstddef>
#include "../iterators/utils.hpp"
#include "../iterators/iterator_set.hpp"
#include "../iterators/reverse_iterator.hpp"

/*
** Sources:
** // https://www.programiz.com/dsa/red-black-tree
*/

#define BLACK 0
#define RED 1

namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {

		/* ************************************************************************** */
		/*                          Member type Definition:                            */
		/* ************************************************************************** */

		public:

			typedef T															key_type;
			typedef key_type							 						value_type;
			typedef Compare 													key_compare;
			typedef Alloc														allocator_type;

			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;

			typedef ft::iterator_set<value_type, true>       					iterator;
    		typedef ft::iterator_set<value_type, true> 							const_iterator;
    		typedef ft::reverse_iterator<iterator>                				reverse_iterator;
    		typedef ft::reverse_iterator<const_iterator>          				const_reverse_iterator;

			typedef ptrdiff_t													difference_type;
    		typedef size_t														size_type;

			typedef RB_Tree_two<value_type>										Tree;
			typedef Tree*														TreePtr;


		private:

			class value_compare {

				friend class set<key_type, key_compare, Alloc>;

				protected:

					Compare comp;
					value_compare (Compare c) : comp(c) {};
				
				public:

					bool operator()(const value_type& x, const value_type& y) const {

						return (comp(x, y));
					};
			};

		/* ************************************************************************** */
		/*                                Attributes:                                 */
		/* ************************************************************************** */

			
			typename allocator_type::template rebind<Tree>::other alloc_node;

			TreePtr 											root;
			TreePtr 											TNULL;

			allocator_type										_alloc;
			size_type											_size;
			key_compare											_comp;


		/* ************************************************************************** */
		/*                               Constructor:                                 */
		/* ************************************************************************** */
		
		public:

			explicit set (const key_compare& comp = key_compare(),
			              const allocator_type& alloc = allocator_type()) {

				_alloc = alloc;
				_comp = comp;
				_size = 0;

				TNULL = alloc_node.allocate(1);
				TNULL->color = BLACK;
				TNULL->left = NULL;
				TNULL->right = NULL;
				TNULL->parent = TNULL;
				TNULL->root = &root;
				TNULL->tNULL = &TNULL;						// change tnull

				root = TNULL;
				_alloc.construct(&root->_pair, value_type());
			};

			template <class InputIterator>
			  set (InputIterator first, InputIterator last,
			       const key_compare& comp = key_compare(),
			       const allocator_type& alloc = allocator_type()) {

				_alloc = alloc;
				_comp = comp;
				_size = 0;

				TNULL = alloc_node.allocate(1);
				TNULL->color = BLACK;
				TNULL->left = NULL;
				TNULL->right = NULL;
				TNULL->parent = TNULL;
				TNULL->root = &root;
				TNULL->tNULL = &TNULL;
				root = TNULL;
				_alloc.construct(&root->_pair, value_type());
				insert(first, last);
			};
		
			set (const set& x) {

				_alloc = x._alloc;
				_comp = x._comp;
				_size = 0;
				
				TNULL = alloc_node.allocate(1);
				TNULL->color = BLACK;
				TNULL->left = NULL;
				TNULL->right = NULL;
				TNULL->parent = TNULL;
				TNULL->root = &root;
				TNULL->tNULL = &TNULL;
				root = TNULL;
				_alloc.construct(&root->_pair, value_type());
				insert(x.begin(), x.end());
			};

			 set& operator= (const set& x) {

				if (this == &x)
				 	return (*this);
				clear();
				insert(x.begin(), x.end());
				return (*this);
			 };

			~set() {

				if (root == TNULL)
				{
					_size = 0;
					deallocate_node(TNULL);
					return ;
				}
				if (_size > 0)
					clear();
				_size = 0;
				deallocate_node(TNULL);
			};

		/* ************************************************************************** */
		/*                                 Iterators:                                 */
		/* ************************************************************************** */
 
			iterator begin() { return iterator(minimum(root)); };
			const_iterator begin() const { return iterator(minimum(root)); };
			
			iterator end() { return (iterator(TNULL)); };
			const_iterator end() const { return iterator(TNULL); };
			
			reverse_iterator rbegin() { return reverse_iterator(end()); };
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };
			
			reverse_iterator rend() { return reverse_iterator(begin());};
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }; 


		/* ************************************************************************** */
		/*                                 Capacity:                                  */
		/* ************************************************************************** */

			bool empty() const {return (size() == 0); };

			size_type size() const { return _size; };

			size_type max_size() const { return _alloc.max_size(); };

		/* ************************************************************************** */
		/*                            	 Modifiers:                                   */
		/* ************************************************************************** */

			pair<iterator, bool> insert (const value_type& val) {

				TreePtr exist = searchTreeHelper(root, val);

				if (exist == TNULL)
				{
					iterator tmp = iterator(insertNode(val));
					return ft::make_pair<iterator, bool>(tmp, true);
				}
				return ft::make_pair<iterator, bool>(iterator(exist), false);
			};

			iterator insert (iterator position, const value_type& val) {

				(void)position;
				return (insert(val).first);

			};
	
			template <class InputIterator>
			  void insert (InputIterator first, InputIterator last) {

				while (first != last)
				{
					insert(*first);
					++first;
				}
			};


			void erase (iterator position) {

				deleteNodeHelper(root, *position);
			};
	
			size_type erase (const key_type& val) {

				TreePtr exist = searchTreeHelper(root, val);

				if (exist != TNULL)
				{
					deleteNodeHelper(root, val);
					return 1;
				}
				return 0;
			};

			void erase (iterator first, iterator last) {

				iterator tmp;

				while (first != last)
				{
					tmp = first++;
					erase(tmp);
				}

			};

			void swap (set& x) {

				TreePtr 	tmp_root;
				TreePtr 	tmp_TNULL;
				size_type 	tmp_size;
				
				tmp_size = _size;
				_size = x._size;
				x._size = tmp_size;

				tmp_root = root;
				root = x.root;
				x.root = tmp_root;

				tmp_TNULL = TNULL;
				TNULL = x.TNULL;
				x.TNULL = tmp_TNULL;

				x.updateRoot(x.root);
				updateRoot(root);

			};

			void clear() {

				delete_tree(root);
				root = TNULL;
				_size = 0;

			};

		/* ************************************************************************** */
		/*                             		Observers:                                */
		/* ************************************************************************** */

			key_compare key_comp() const { 
				
				return (key_compare());
			};


			value_compare value_comp() const {

				return (value_compare(key_compare()));
			};

		/* ************************************************************************** */
		/*                            		Operations:                               */
		/* ************************************************************************** */


			iterator find (const value_type& val) const {

				TreePtr tmp = searchTreeHelper(root, val);

				if (tmp != TNULL)
					return (iterator(tmp));
				else
					return (end());
			};
		
			size_type count (const value_type& val) const {

				return (searchTreeHelper(root, val) != TNULL);
			};


			iterator lower_bound (const value_type& val) const {

				iterator itb = begin();
				iterator ite = end();

				while (itb != ite)
				{
					if (_comp((*itb), val) == false)
						break;
					itb++;
				}
				return (itb);
			};

			iterator upper_bound (const value_type& val) const {
	
				iterator itb = begin();
				iterator ite = end();

				while (itb != ite)
				{
					if (_comp(val, (*itb)))
						break;
					itb++;
				}
				return itb;

			};


			pair<iterator,iterator>             equal_range (const value_type& val) const {
				
				return (ft::make_pair(lower_bound(val), upper_bound(val)));

			};

		/* ************************************************************************** */
		/*                           		Allocator:                                */
		/* ************************************************************************** */

			allocator_type get_allocator() const {

				return allocator_type();
			};


		/* ************************************************************************** */
		/*                            Red-Black Tree Algorithm:                       */
		/* ************************************************************************** */
		/* ************************************************************************** */
		/*                              	Rotation :				                  */
		/* ************************************************************************** */

		private:
		
			void preorder() {
				preOrderHelper(this->root);
			};

			void inorder() {
				inOrderHelper(this->root);
			};

			void postorder() {
				postOrderHelper(this->root);
			};

			void preOrderHelper(TreePtr node) {

				if (node != TNULL) 
				{
					std::cout << node->data << " ";
					preOrderHelper(node->left);
					preOrderHelper(node->right);
				}
			};

			void inOrderHelper(TreePtr node) {

				if (node != TNULL) 
				{
					inOrderHelper(node->left);
					std::cout << node->data << " ";
					inOrderHelper(node->right);
				}
			};

			void postOrderHelper(TreePtr node) {

				if (node != TNULL) 
				{
					postOrderHelper(node->left);
					postOrderHelper(node->right);
					std::cout << node->data << " ";
				}
			};

			void rbTransplant(TreePtr u, TreePtr v) 
			 {
				if (u->parent == NULL)
					root = v;
				else if (u == u->parent->left) 
					u->parent->left = v;
				else 
					u->parent->right = v;
				v->parent = u->parent;
			};

			TreePtr predecessor(TreePtr x) {

				if (x->left != TNULL) 
					return maximum(x->left);
				TreePtr y = x->parent;
				while (y != TNULL && x == y->left) 
				{
					x = y;
					y = y->parent;
				}
				return y;
			};

			TreePtr successor(TreePtr x) {

				if (x->right != TNULL)
					return minimum(x->right);
				TreePtr y = x->parent;
				while (y != TNULL && x == y->right) 
				{
					x = y;
					y = y->parent;
				}
				return y;
			};

			void leftRotate(TreePtr x) {
	
				TreePtr y = x->right;
				x->right = y->left;
				if (y->left != TNULL) 
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL) 
					this->root = y;
				else if (x == x->parent->left) 
					x->parent->left = y;
				else 
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			};

			void rightRotate(TreePtr x) {
	
				TreePtr y = x->left;
				x->left = y->right;
				if (y->right != TNULL) 
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL) 
					this->root = y;
				else if (x == x->parent->right) 
					x->parent->right = y;
				else 
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			};

		/* ************************************************************************** */
		/*                              	Delete :				                  */
		/* ************************************************************************** */

			void deleteNode(value_type data) {

				deleteNodeHelper(this->root, data);
				_size--;
			};


			void delete_tree( TreePtr p) {

				if (p != TNULL)
				{
					delete_tree(p->left);
					delete_tree(p->right);
					deallocate_node(p);
					_size--;
				}
			};

			void deleteNodeHelper(TreePtr node, const key_type& key) {

				TreePtr x;
				TreePtr y;
				TreePtr z = TNULL;
				
				while (node != TNULL) 
				{
					if (node->_pair == key) 
						z = node;
					if (node->_pair <= key) 
						node = node->right;
					else 
						node = node->left;
				}
				if (z == TNULL) 
				{
					std::cout << "Key not found" << std::endl;
					return;
				}
				y = z;
				int y_original_color = y->color;

				if (z->left == TNULL) 
				{
					x = z->right;
					rbTransplant(z, z->right);
				}
				else if (z->right == TNULL) 
				{
					x = z->left;
					rbTransplant(z, z->left);
				} 
				else 
				{
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z) {
						x->parent = y;
				} 
				else 
				{
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				deallocate_node(z);
				_size--;

				if (y_original_color == BLACK) {
					deleteFix(x);
				}
			};

			void deleteFix(TreePtr x) {

				TreePtr s;
				
				while (x != root && x->color == BLACK) 
				{
					if (x == x->parent->left) 
					{
						s = x->parent->right;
						if (s->color == RED) 
						{
							s->color = BLACK;
							x->parent->color = 1;
							leftRotate(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								rightRotate(s);
								s = x->parent->right;
							}

							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							leftRotate(x->parent);
							x = root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							rightRotate(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == BLACK && s->right->color == 0)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								leftRotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							rightRotate(x->parent);
							x = root;
						}
					}
				}
				x->color = BLACK;
			};

			void	deallocate_node(TreePtr node) {

					_alloc.destroy(&node->_pair);
					alloc_node.deallocate(node, 1);
			};

		/* ************************************************************************** */
		/*                              	Insert :				                  */
		/* ************************************************************************** */

			TreePtr insertNode(const value_type& val) {

				TreePtr node = alloc_node.allocate(1);
				node->parent = NULL;
				_alloc.construct(&node->_pair, val);
				node->left = TNULL;
				node->right = TNULL;
				node->color = RED;
				node->tNULL = &TNULL;
				_size++;
				TreePtr y = NULL;
				TreePtr x = this->root;

				while (x != TNULL) 
				{
					y = x;
					if (_comp(node->_pair, x->_pair))
						x = x->left;
					else 
						x = x->right;
				}
				node->parent = y;
				if (y == NULL) 
					root = node;
				else if (_comp(node->_pair, y->_pair)) 
					y->left = node;
				else 
					y->right = node;
				if (node->parent == NULL) 
				{
					node->root = &root;
					node->color = BLACK;
					return node;
				}
				if (node->parent->parent == NULL)
				{
					node->root = &root; 
					return node;
				}
				insertFix(node);
				node->root = &root;
				return node;
			};

			void insertFix(TreePtr k) {

				TreePtr u;
				while (k->parent->color == 1) 
				{
					if (k->parent == k->parent->parent->right) 
					{
						u = k->parent->parent->left;
						if (u->color == 1) 
						{
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						}
						else 
						{
							if (k == k->parent->left) 
							{
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							leftRotate(k->parent->parent);
						}
					}
					else 
					{
						u = k->parent->parent->right;
						if (u->color == 1) 
						{
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						} 
						else 
						{
							if (k == k->parent->right) 
							{
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							rightRotate(k->parent->parent);
						}
					}
					if (k == root)
						break;
				}
					root->color = BLACK;
			};


			TreePtr minimum(TreePtr node) const {
			
				if (node == TNULL)
					return node;
				while (node->left != TNULL)
					node = node->left;
				return node;
			};

			TreePtr maximum(TreePtr node) const {

				if (node == TNULL)
					return node;
				while (node->right != TNULL)
					node = node->right;
				return node;
			};


			TreePtr searchTree(int k) {

				return searchTreeHelper(this->root, k);
			};

			TreePtr	searchTreeHelper(TreePtr node, const key_type& key) const {

				if (node == TNULL || key == node->_pair)
					return node;
				if (_comp(key, node->_pair)) 
					return searchTreeHelper(node->left, key);
				return searchTreeHelper(node->right, key);
			};

			void	updateRoot(TreePtr n) {

					if (n->left)
						updateRoot(n->left);
					if (n->right)
						updateRoot(n->right);
					n->root = &root;
					n->tNULL = &TNULL;

			};
	};

	template< class Key, class Compare, class Alloc >
	bool operator == ( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
			
		typename ft::set<Key,Compare,Alloc>::const_iterator first = rhs.begin();
		typename ft::set<Key,Compare,Alloc>::const_iterator last = rhs.end();
		typename ft::set<Key,Compare,Alloc>::const_iterator cursor = lhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
	};

	template< class Key, class Compare, class Alloc >
	bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); };

	template< class Key, class Compare, class Alloc >
	bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
			
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template< class Key, class Compare, class Alloc >
	bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) { return (!(rhs < lhs)); };

	template< class Key, class Compare, class Alloc >
	bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) { return (rhs < lhs); };
	
	template< class Key, class Compare, class Alloc >
	bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) { return (!(rhs > lhs)); };

	template< class Key, class Compare, class Alloc >
	void swap( ft::set<Key,Compare,Alloc>& lhs, ft::set<Key,Compare,Alloc>& rhs ) { lhs.swap(rhs); };

};

#endif