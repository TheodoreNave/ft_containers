#include "../containers/set.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <cstddef>
#include <set>
#include <type_traits>

#define STD_GREEN "\033[1m\033[32m"
#define FT_BLUE "\033[1m\033[36m"
#define HEAD "\033[1m\033[31m"
#define SUB_HEAD "\033[1m\033[33m"
#define SUB_SUB_HEAD "\033[1m\033[35m"

// /* ************************************************************************** */
// /*                                	BASICS :                                  */
// /* ************************************************************************** */

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
void ft_basic_set(T1 &std, T2 &ft) {

	std::set<int>::iterator itb_std = std.begin();
	std::set<int>::iterator ite_std = std.end();

	ft::set<int>::iterator itb_ft = ft.begin();
	ft::set<int>::iterator ite_ft = ft.end();


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout <<std::endl;

	// ft_print(std, 5);
	while (itb_std != ite_std) {

		std::cout  << "Value : " <<  (*itb_std) << std::endl;
		++itb_std;
	}
	std::cout <<std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout <<std::endl;
	while (itb_ft != ite_ft) {

		std::cout <<  "Value : " << (*itb_ft) << std::endl;
		++itb_ft;
	}

	std::cout <<std::endl;
}

// /* ************************************************************************** */
// /*                                	ITERATORS :                               */
// /* ************************************************************************** */


template <class T1, class T2>
void ft_iterator(T1 &std, T2 &ft) {

	std::set<int>::iterator itb_std = std.begin();
	std::set<int>::iterator ite_std = std.end();
	
	std::set<int>::reverse_iterator ritb_std = std.rbegin();
	std::set<int>::reverse_iterator rite_std = std.rend();

	ft::set<int>::iterator itb_ft = ft.begin();
	ft::set<int>::iterator ite_ft = ft.end();

	ft::set<int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::set<int>::reverse_iterator rite_ft = ft.rend();

	std::set<int, std::string> test_str;

	ft::set<int, std::string> test_str_two;

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  Reverse:        */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout << STD_GREEN << "----------------Rev : ------------------" << std::endl;

	while (ritb_std != rite_std) {

		std::cout << "Value : " <<  (*ritb_std) << std::endl;
		++ritb_std;
	}

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout << FT_BLUE << "----------------Rev : ------------------" << std::endl;


	while (ritb_ft != rite_ft) {

		std::cout  <<  "Value : " << (*ritb_ft) << std::endl;
		++ritb_ft;
	}
	
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  other_tests:    */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

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

	std::cout  << "Value : " <<  (*itb_std) << std::endl;
	std::cout  << "Value : " <<  (*ite_std) << std::endl;
	// std::cout << (*ite_std) << std::endl;

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

	std::cout << "Value : " <<  (*itb_ft) << std::endl;
	std::cout << "Value : " <<  (*ite_ft) << std::endl;


}

// /* ************************************************************************** */
// /*                                	CAPACITY :                                */
// /* ************************************************************************** */

template <class T1, class T2>
void ft_capacity(T1 &std, T2 &ft) {

	std::set<int>::iterator itb_std = std.begin();
	std::set<int>::iterator ite_std = std.end();
	
	std::set<int>::reverse_iterator ritb_std = std.rbegin();
	std::set<int>::reverse_iterator rite_std = std.rend();

	ft::set<int>::iterator itb_ft = ft.begin();
	ft::set<int>::iterator ite_ft = ft.end();

	ft::set<int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::set<int>::reverse_iterator rite_ft = ft.rend();

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  size:           */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	print_size(std);

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	print_size(ft);
	


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
}


// /* ************************************************************************** */
// /*                                	MODIFIERS :                               */
// /* ************************************************************************** */

template <class T1, class T2>
void ft_modifiers_others(T1 &std, T2 &ft) {

	std::set<int>::iterator itb_std = std.begin();
	std::set<int>::iterator ite_std = std.end();
	
	ft::set<int>::iterator itb_ft = ft.begin();
	ft::set<int>::iterator ite_ft = ft.end();

	std::set<int> test;
	ft::set<int> test_two;
	

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*     ERASE :      */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	std.erase(3);
	while (itb_std != ite_std) {

		std::cout  << "Value : " <<  (*itb_std) << std::endl;
		++itb_std;
	}

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	ft.erase(3);
	while (itb_ft != ite_ft) {

		std::cout << "Value : " <<  (*itb_ft) << std::endl;
		++itb_ft;
	}

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	std::cout << *std.find(5)  << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	std::cout << *ft.find(5)  << std::endl;


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

	if (std==std) std::cout << "std and std are equal\n";
	if (std!=std) std::cout << "std and std are not equal\n";
	if (std< std) std::cout << "std is less than std\n";
	if (std> std) std::cout << "std is greater than std\n";
	if (std<=std) std::cout << "std is less than or equal to std\n";
	if (std>=std) std::cout << "std is greater than or equal to std\n";

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	if (ft==ft) std::cout << "ft and ft are equal\n";
	if (ft!=ft) std::cout << "ft and ft are not equal\n";
	if (ft< ft) std::cout << "ft is less than ft\n";
	if (ft> ft) std::cout << "ft is greater than ft\n";
	if (ft<=ft) std::cout << "ft is less than or equal to ft\n";
	if (ft>=ft) std::cout << "ft is greater than or equal to ft\n";


}

int main() {
	

	std::cout <<  HEAD << "		   	/* ========================================================================= */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                                                    	     */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                   SET :                                   */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                                                     	     */"	<< std::endl;
	std::cout <<  HEAD << "		   	/* ========================================================================= */"	<< std::endl;
	std::cout << std::endl;
	{

		std::set<int> one;
		std::set<int> one_bis;
		std::set<int> one_two;

		ft::set<int> five;
		ft::set<int> five_bis;
		ft::set<int> five_two;

		for (int i = 5; i < 15 ; i++) {

			one.insert(i);
			five.insert(i);
		}

		for (int i = 5; i < 15 ; i++) {

			one_bis.insert(i);
			five_bis.insert(i);
		}

		for (int i = 5; i < 15 ; i++) {

			one_two.insert(i);
			five_two.insert(i);
		}

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                    CONSTRUCT BASICS :                   */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_basic_set(one, five);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                         ITERATORS :                     */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_iterator(one, five);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                         CAPACITY :                      */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_capacity(one, five);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                         MODIFIERS :                     */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_modifiers_others(one_two, five_two);
	}
	return (0);
}
