#include "../containers/vector.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <cstddef>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <type_traits>
#include <vector>
#include <map>
#include <stack>
#include <set>

#define STD_GREEN "\033[1m\033[32m"
#define FT_BLUE "\033[1m\033[36m"
#define HEAD "\033[1m\033[31m"
#define SUB_HEAD "\033[1m\033[33m"
#define SUB_SUB_HEAD "\033[1m\033[35m"

/* ************************************************************************** */
/*                                	BASICS :                                  */
/* ************************************************************************** */

template <class T1>
void	print_size(T1 &container) {

	std::cout << container.size() << std::endl;
	return ;
};

template <class T1, class T2>
void	ft_reset(T1 &std, T2 &ft) {

	std.clear();
	ft.clear();
	std.erase(std.begin(), std.end());
	ft.erase(ft.begin(), ft.end());

	std.resize(1);
	ft.resize(1);

}

template <class T1>
void	ft_print(T1 &container, int num) {

	for (int i = 0 ; i < num ; i++) {

		std::cout << container[i] << std::endl;
	}
};

template <class T1, class T2>
void	add_number(T1 &std, T2 &ft) {

	for (int i = 1 ; i <= 10 ; i++) {

			std.push_back(i);
			ft.push_back(i);
	}
}

template <class T1, class T2>
void ft_basic_vec(T1 &std, T2 &ft) {

	std::vector<int>::iterator itb_std = std.begin();
	std::vector<int>::iterator ite_std = std.end();

	ft::vector<int>::iterator itb_ft = ft.begin();
	ft::vector<int>::iterator ite_ft = ft.end();

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout <<std::endl;
	while (itb_std != ite_std) {

		std::cout << *itb_std << std::endl;
		++itb_std;
	}
	std::cout <<std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout <<std::endl;
	while (itb_ft != ite_ft) {

		std::cout << *itb_ft << std::endl;
		++itb_ft;
	}

	std::cout <<std::endl;
}

/* ************************************************************************** */
/*                                	ITERATORS :                               */
/* ************************************************************************** */


template <class T1, class T2>
void ft_iterator(T1 &std, T2 &ft) {

	std::vector<int>::iterator itb_std = std.begin();
	std::vector<int>::iterator ite_std = std.end();
	
	std::vector<int>::reverse_iterator ritb_std = std.rbegin();
	std::vector<int>::reverse_iterator rite_std = std.rend();

	ft::vector<int>::iterator itb_ft = ft.begin();
	ft::vector<int>::iterator ite_ft = ft.end();

	ft::vector<int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::vector<int>::reverse_iterator rite_ft = ft.rend();

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  Reverse:        */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout << STD_GREEN << "----------------Rev : ------------------" << std::endl;

	while (ritb_std != rite_std) {

		std::cout << *ritb_std << std::endl;
		++ritb_std;
	}

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout << FT_BLUE << "----------------Rev : ------------------" << std::endl;


	while (ritb_ft != rite_ft) {

		std::cout << *ritb_ft << std::endl;
		++ritb_ft;
	}
	
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  other_tests:    */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout << STD_GREEN << "---------------- Calcul : ------------------" << std::endl;

	for (int i = 0; i < 6; ++i)
		itb_std[i] = (7 - i) * 2;

	itb_std = itb_std + 2;
	std::cout << *itb_std << std::endl;

	std::cout << *--ite_std << std::endl;
	std::cout << *ite_std-- << std::endl;


	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout << FT_BLUE << "---------------- Calcul : ------------------" << std::endl;

	for (int i = 0; i < 6; ++i)
		itb_ft[i] = (7 - i) * 2;

	itb_ft = itb_ft + 2;
	std::cout << *itb_ft << std::endl;

	std::cout << *--ite_ft << std::endl;
	std::cout << *ite_ft-- << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout << STD_GREEN << "---------------- ++ -- : ------------------" << std::endl;

	++itb_std;
	++itb_std;
	++itb_std;
	++itb_std;
	itb_std--;
	ite_std--;
	ite_std--;
	ite_std--;
	ite_std--;

	std::cout << *itb_std << std::endl;
	std::cout << *ite_std << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout << FT_BLUE << "---------------- ++ -- : ------------------" << std::endl;

	++itb_ft;
	++itb_ft;
	++itb_ft;
	++itb_ft;
	itb_ft--;
	ite_ft--;
	ite_ft--;
	ite_ft--;
	ite_ft--;

	std::cout << *itb_ft << std::endl;
	std::cout << *ite_ft << std::endl;

}

template <class T1, class T2>
void ft_const_iterator(T1 &std, T2 &ft) {

	std::vector<int>::iterator itb_std = std.begin();
	std::vector<int>::iterator ite_std = std.end();

	std::vector<int>::const_iterator c_itb_std = std.begin();
	std::vector<int>::const_iterator c_ite_std = std.end();
	
	std::vector<int>::const_reverse_iterator c_ritb_std = std.rbegin();
	std::vector<int>::reverse_iterator c_rite_std = std.rend();

	ft::vector<int>::iterator itb_ft = ft.begin();
	ft::vector<int>::iterator ite_ft = ft.end();

	ft::vector<int>::const_iterator c_itb_ft = ft.begin();
	ft::vector<int>::const_iterator c_ite_ft = ft.end();

	ft::vector<int>::const_reverse_iterator c_ritb_ft = ft.rbegin();
	ft::vector<int>::const_reverse_iterator c_rite_ft = ft.rend();

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  Reverse:        */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	while (c_itb_std != c_ite_std) {

		std::cout << *c_itb_std << std::endl;
		++c_itb_std;
	}

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	while (c_itb_ft != c_ite_ft) {

		std::cout << *c_itb_ft << std::endl;
		++c_itb_ft;
	}
	
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  other_tests:    */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	c_itb_std = itb_std + 2;
	std::cout << *c_itb_std << std::endl;


	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;


	c_itb_ft = itb_ft + 2;
	std::cout << *c_itb_ft << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	++c_itb_std;
	++c_itb_std;
	++c_itb_std;
	++c_itb_std;
	c_itb_std--;
	c_ite_std--;
	c_ite_std--;
	c_ite_std--;
	c_ite_std--;

	std::cout << *c_itb_std << std::endl;
	std::cout << *c_ite_std << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	++c_itb_ft;
	++c_itb_ft;
	++c_itb_ft;
	++c_itb_ft;
	c_itb_ft--;
	c_ite_ft--;
	c_ite_ft--;
	c_ite_ft--;
	c_ite_ft--;

	std::cout << *c_itb_ft << std::endl;
	std::cout << *c_ite_ft << std::endl;

}

/* ************************************************************************** */
/*                                	CAPACITY :                                */
/* ************************************************************************** */

template <class T1, class T2>
void ft_capacity(T1 &std, T2 &ft) {

	std::vector<int>::iterator itb_std = std.begin();
	std::vector<int>::iterator ite_std = std.end();
	
	std::vector<int>::reverse_iterator ritb_std = std.rbegin();
	std::vector<int>::reverse_iterator rite_std = std.rend();

	ft::vector<int>::iterator itb_ft = ft.begin();
	ft::vector<int>::iterator ite_ft = ft.end();

	ft::vector<int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::vector<int>::reverse_iterator rite_ft = ft.rend();

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  size:           */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	print_size(std);

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	print_size(ft);

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  max_size:       */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;


	std::cout << std.max_size() << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	std::cout << ft.max_size() << std::endl;		

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  resize:         */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	std::cout << "===OG_SIZE===" << std::endl;
	print_size(std);

	std.resize(5, 10);
	std::cout << "===RESIZING===" << std::endl;

	print_size(std);

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	std::cout << "===OG_SIZE===" << std::endl;
	print_size(ft);

	ft.resize(5, 10);
	std::cout << "===RESIZING===" << std::endl;

	print_size(ft);

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  capacity:       */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD-CAPACITY : ------------------" << std::endl;

	std::cout << std.capacity() << std::endl;
	std::cout << FT_BLUE << "----------------FT-CAPACITY : ------------------" << std::endl;
	std::cout << ft.capacity() << std::endl;

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  empty:          */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	if (std.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;
	
	std::cout << "======> clear the container " << std::endl;
	std.clear();

	if (std.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	if (ft.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;

	std::cout << "======> clear the container " << std::endl;
	ft.clear();

	if (ft.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  reserve:        */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	std::cout << std.capacity() << std::endl;
	std.reserve(50);
	std::cout << std.capacity() << std::endl;


	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	std::cout << ft.capacity() << std::endl;
	ft.reserve(50);
	std::cout << ft.capacity() << std::endl;
}

/* ************************************************************************** */
/*                                	ELEMENT ACCESS :                          */
/* ************************************************************************** */

template <class T1, class T2>
void ft_element_access(T1 &std, T2 &ft) {

	std::vector<int>::iterator itb_std = std.begin();
	std::vector<int>::iterator ite_std = std.end();
	
	std::vector<int>::reverse_iterator ritb_std = std.rbegin();
	std::vector<int>::reverse_iterator rite_std = std.rend();

	ft::vector<int>::iterator itb_ft = ft.begin();
	ft::vector<int>::iterator ite_ft = ft.end();

	ft::vector<int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::vector<int>::reverse_iterator rite_ft = ft.rend();

	std::vector<int>::size_type size = std.size();

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*     operator []: */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	for (int i = 0 ; i < 2 * size ; i ++)
		std[i] = i + size / 2;

	for (int i = 0 ; i < 10 ; i++)
		std::cout << "std[i] = " << std[i] << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	for (int i = 0 ; i < 2 * size ; i ++)
		ft[i] = i + size / 2;

	for (int i = 0 ; i < 10 ; i++)
		std::cout << "ft[i] = " << ft[i] << std::endl;

};

template <class T1, class T2>
void ft_element_acces_two(T1 &std, T2 &ft) {

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*        AT :      */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	for (int i = 0 ; i < 5 ; i ++)
	{
		std::cout << std.at(8 / 2) << std::endl;
	}

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	for (int i = 0 ; i < 5 ; i ++)
	{
		std::cout << ft.at(8 / 2) << std::endl;
	}

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*   FRONT / BACK : */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	
	std::cout << "FRONT" << std::endl;
	// std.front() -= std.back();
	std::cout << std.front() << std::endl;
	std::cout << "BACK" << std::endl;
	std::cout << std.back() << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	
	std::cout << "FRONT" << std::endl;
	std::cout << ft.front() << std::endl;
	std::cout << "BACK" << std::endl;
	std::cout << ft.back() << std::endl;

}

/* ************************************************************************** */
/*                                	MODIFIERS :                               */
/* ************************************************************************** */

template <class T1, class T2>
void ft_modifiers_others(T1 &std, T2 &ft) {

	std::vector<int>::iterator itb_std = std.begin();
	std::vector<int>::iterator ite_std = std.end();
	
	std::vector<int>::reverse_iterator ritb_std = std.rbegin();
	std::vector<int>::reverse_iterator rite_std = std.rend();

	ft::vector<int>::iterator itb_ft = ft.begin();
	ft::vector<int>::iterator ite_ft = ft.end();

	ft::vector<int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::vector<int>::reverse_iterator rite_ft = ft.rend();

	std::vector<int> test;
	ft::vector<int> test_two;

	add_number(test, test_two);


	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*      ASSIGN :    */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	std::cout << "Size is :" << std::endl;
	print_size(std);
	std::cout << "First assign => 5 x reverse" << std::endl;	
	std.assign(ritb_std, rite_std);

	ft_print(std, 10);

	std::cout << "Second assign => 5 times 123" << std::endl;	
	std.assign(5, 123);
	
	ft_print(std, 10);


	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	
	std::cout << "Size is :" << std::endl;
	print_size(ft);
	std::cout << "First assign => 5 x reverse" << std::endl;	
	ft.assign(ritb_ft, rite_ft + 2);
	ft_print(ft, 10);

	std::cout << "Second assign => 5 x 123" << std::endl;	
	ft.assign(5, 123);
	ft_print(ft, 10);


	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*    PUSH / POP :  */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;


	test.push_back(42);
	test.push_back(6);
	test.push_back(1);
	test.push_back(911);
	test.push_back(2);
	test.push_back(3);
	test.push_back(90);


	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();

	ft_print(test, 17);

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	test_two.push_back(42);
	test_two.push_back(6);
	test_two.push_back(1);
	test_two.push_back(911);
	test_two.push_back(2);
	test_two.push_back(3);
	test_two.push_back(90);

	test_two.pop_back();
	test_two.pop_back();
	test_two.pop_back();
	test_two.pop_back();
	test_two.pop_back();
	test_two.pop_back();
	
	
	ft_print(test, 17);

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*     INSERT :     */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;


	std::cout << "Single element" << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		std[i] = i;
	} 

	std.insert(itb_std + 3, 42);

	ft_print(std, 6);

	std::cout << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		std[i] = i;
	} 

	std::cout << "Fill" << std::endl;

	std.insert(itb_std + 1, 3, 42);


	ft_print(std, 6);


	std::cout << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		std[i] = i;
	} 

	std::cout << "Range" << std::endl;

	std.insert(itb_std + 2, itb_std, ite_std);

	ft_print(std, 4);

	
	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	std::cout << "Single element" << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		ft[i] = i;
	} 

	ft.insert(itb_ft + 3, 42);

	ft_print(ft, 6);

	std::cout << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		ft[i] = i;
	} 

	std::cout << "Fill" << std::endl;

	ft.insert(itb_ft + 1, 3, 42);


	ft_print(ft, 6);


	std::cout << std::endl;

	for (int i = 0 ; i < 4 ; i++) {

		ft[i] = i;
	} 

	std::cout << "Range" << std::endl;

	ft.insert(itb_ft + 2, itb_ft, ite_ft);

	ft_print(ft, 4);


	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*     ERASE :      */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		std[i] = i;
	} 
	std.erase(itb_std + 2);
	ft_print(std, 5);


	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		ft[i] = i;
	} 
	ft.erase(itb_ft + 2);

		ft_print(ft, 5);

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*       CLEAR :    */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	std::cout << "size before: " << std::endl;
	print_size(std);

	std.clear();
	std::cout << "size after: " << std::endl;
	print_size(std);


	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	std::cout << "size before: "<< std::endl;
	print_size(ft);
	ft.clear();
	std::cout << "size after: " << std::endl;
	print_size(ft);

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*       OTHERS :   */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	if (std==test) std::cout << "std and test are equal\n";
	if (std!=test) std::cout << "std and test are not equal\n";
	if (std< test) std::cout << "std is less than test\n";
	if (std> test) std::cout << "std is greater than test\n";
	if (std<=test) std::cout << "std is less than or equal to test\n";
	if (std>=test) std::cout << "std is greater than or equal to test\n";

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	if (ft==test_two) std::cout << "ft and test_two are equal\n";
	if (ft!=test_two) std::cout << "ft and test_two are not equal\n";
	if (ft< test_two) std::cout << "ft is less than test_two\n";
	if (ft> test_two) std::cout << "ft is greater than test_two\n";
	if (ft<=test_two) std::cout << "ft is less than or equal to test_two\n";
	if (ft>=test_two) std::cout << "ft is greater than or equal to test_two\n";
};

int main() {
	

	std::cout <<  HEAD << "		   	/* ========================================================================= */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                                                    	     */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                VECTOR :                                   */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                                                     	     */"	<< std::endl;
	std::cout <<  HEAD << "		   	/* ========================================================================= */"	<< std::endl;
	std::cout << std::endl;
	{

		std::vector<int> one;										// Basic
		std::vector<int> one_bis;									// Another Basic
		std::vector<int> two (9, 90);								// with param
		std::vector<int> three (two.begin(), two.end());			// iterator constructor
		std::vector<int> four (three);								// copy constructor

		ft::vector<int> five;
		ft::vector<int> five_bis;
		ft::vector<int> six (9, 90);
		ft::vector<int> seven (six.begin(), six.end());
		ft::vector<int> eight (seven);

		add_number(one, five);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                    CONSTRUCT BASICS :                   */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_basic_vec(one, five);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                         ITERATORS :                     */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_iterator(one, five);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                      CONST_ITERATORS :                  */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_const_iterator(two, six);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                         CAPACITY :                      */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_capacity(two, six);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                       ELEMENT ACCESS :                  */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;
		
		ft_element_access(one, five);

		add_number(one_bis, five_bis);
		ft_element_acces_two(one_bis, five_bis);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                         MODIFIERS :                     */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		add_number(two, six);
		ft_modifiers_others(two, six);
	}
	return (0);
}
