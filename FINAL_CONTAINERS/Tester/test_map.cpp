#include "../containers/map.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <cstddef>
#include <map>
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
void ft_basic_map(T1 &std, T2 &ft) {

	std::map<int, int>::iterator itb_std = std.begin();
	std::map<int, int>::iterator ite_std = std.end();

	ft::map<int, int>::iterator itb_ft = ft.begin();
	ft::map<int, int>::iterator ite_ft = ft.end();


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout <<std::endl;

	// ft_print(std, 5);
	while (itb_std != ite_std) {

		std::cout << "Key : " << (*itb_std).first << '\t' << "Value : " <<  (*itb_std).second << std::endl;
		++itb_std;
	}
	std::cout <<std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout <<std::endl;
	while (itb_ft != ite_ft) {

		std::cout << "Key : " << (*itb_ft).first << '\t' <<  "Value : " << (*itb_ft).second << std::endl;
		++itb_ft;
	}

	std::cout <<std::endl;
}

// /* ************************************************************************** */
// /*                                	ITERATORS :                               */
// /* ************************************************************************** */


template <class T1, class T2>
void ft_iterator(T1 &std, T2 &ft) {

	std::map<int, int>::iterator itb_std = std.begin();
	std::map<int, int>::iterator ite_std = std.end();
	
	std::map<int, int>::reverse_iterator ritb_std = std.rbegin();
	std::map<int, int>::reverse_iterator rite_std = std.rend();

	ft::map<int, int>::iterator itb_ft = ft.begin();
	ft::map<int, int>::iterator ite_ft = ft.end();

	ft::map<int, int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::map<int, int>::reverse_iterator rite_ft = ft.rend();

	std::map<int, std::string> test_str;

	ft::map<int, std::string> test_str_two;

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  Reverse:        */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout << STD_GREEN << "----------------Rev : ------------------" << std::endl;

	while (ritb_std != rite_std) {

		std::cout << "Key : " << (*ritb_std).first << '\t' << "Value : " <<  (*ritb_std).second << std::endl;
		++ritb_std;
	}

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout << FT_BLUE << "----------------Rev : ------------------" << std::endl;


	while (ritb_ft != rite_ft) {

		std::cout << "Key : " << (*ritb_ft).first << '\t' <<  "Value : " << (*ritb_ft).second << std::endl;
		++ritb_ft;
	}
	
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  other_tests:    */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;
	std::cout << STD_GREEN << "---------------- Str : ------------------" << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		test_str[i] = "Hello";
		std::cout << test_str[i] << std::endl;
	}

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;
	std::cout << FT_BLUE << "---------------- Str : ------------------" << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		test_str_two[i] = "Hello";
		std::cout << test_str_two[i] << std::endl;
	}

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

	std::cout << "Key : " << (*itb_std).first << '\t' << "Value : " <<  (*itb_std).second << std::endl;
	std::cout << "Key : " << (*ite_std).first << '\t' << "Value : " <<  (*ite_std).second << std::endl;
	// std::cout << (*ite_std).first << std::endl;

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

	std::cout << "Key : " << (*itb_ft).first << '\t' << "Value : " <<  (*itb_ft).second << std::endl;
	std::cout << "Key : " << (*ite_ft).first << '\t' << "Value : " <<  (*ite_ft).second << std::endl;


}

// /* ************************************************************************** */
// /*                                	CAPACITY :                                */
// /* ************************************************************************** */

template <class T1, class T2>
void ft_capacity(T1 &std, T2 &ft) {

	std::map<int, int>::iterator itb_std = std.begin();
	std::map<int, int>::iterator ite_std = std.end();
	
	std::map<int, int>::reverse_iterator ritb_std = std.rbegin();
	std::map<int, int>::reverse_iterator rite_std = std.rend();

	ft::map<int, int>::iterator itb_ft = ft.begin();
	ft::map<int, int>::iterator ite_ft = ft.end();

	ft::map<int, int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::map<int, int>::reverse_iterator rite_ft = ft.rend();

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
// /*                                	ELEMENT ACCESS :                          */
// /* ************************************************************************** */

template <class T1, class T2>
void ft_element_access(T1 &std, T2 &ft) {

	std::map<int, int>::iterator itb_std = std.begin();
	std::map<int, int>::iterator ite_std = std.end();
	
	std::map<int, int>::reverse_iterator ritb_std = std.rbegin();
	std::map<int, int>::reverse_iterator rite_std = std.rend();

	ft::map<int, int>::iterator itb_ft = ft.begin();
	ft::map<int, int>::iterator ite_ft = ft.end();

	ft::map<int, int>::reverse_iterator ritb_ft = ft.rbegin();
	ft::map<int, int>::reverse_iterator rite_ft = ft.rend();

	std::map<int, int>::size_type size = std.size();

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

// /* ************************************************************************** */
// /*                                	MODIFIERS :                               */
// /* ************************************************************************** */

template <class T1, class T2>
void ft_modifiers_others(T1 &std, T2 &ft) {

	std::map<int, int>::iterator itb_std = std.begin();
	std::map<int, int>::iterator ite_std = std.end();
	
	ft::map<int, int>::iterator itb_ft = ft.begin();
	ft::map<int, int>::iterator ite_ft = ft.end();

	std::map<int, int> test;
	ft::map<int, int> test_two;
	

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*     ERASE :      */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;


	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		std[i] = i;
	} 

	std.erase(3);
	while (itb_std != ite_std) {

		std::cout << "Key : " << (*itb_std).first << '\t' << "Value : " <<  (*itb_std).second << std::endl;
		++itb_std;
	}

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	for (int i = 0 ; i < 6 ; i++) {

		ft[i] = i;
	} 
	ft.erase(3);
	while (itb_ft != ite_ft) {

		std::cout << "Key : " << (*itb_ft).first << '\t' << "Value : " <<  (*itb_ft).second << std::endl;
		++itb_ft;
	}

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
	std::cout <<  HEAD << "		   	/*                                   MAP :                                   */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                                                     	     */"	<< std::endl;
	std::cout <<  HEAD << "		   	/* ========================================================================= */"	<< std::endl;
	std::cout << std::endl;
	{

		std::map<int, int> one;
		std::map<int, int> one_bis;
		std::map<int, int> one_two;

		ft::map<int, int> five;
		ft::map<int, int> five_bis;
		ft::map<int, int> five_two;

		for (int i = 0; i < 10 ; i++) {

			one.insert(std::pair< int, int>(i, i + 42));
			five.insert(ft::pair< int, int>(i, i + 42));
		}

		for (int i = 0; i < 10 ; i++) {

			one_bis.insert(std::pair< int, int>(i, i + 35));
			five_bis.insert(ft::pair< int, int>(i, i + 35));
		}

		for (int i = 0; i < 10 ; i++) {

			one_two.insert(std::pair< int, int>(i, i + 12));
			five_two.insert(ft::pair< int, int>(i, i + 12));
		}
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                    CONSTRUCT BASICS :                   */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_basic_map(one, five);

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
		std::cout <<  SUB_HEAD << "				 /*                       ELEMENT ACCESS :                  */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;
		
		ft_element_access(one_bis, five_bis);

		// add_number(one_bis, five_bis);

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                         MODIFIERS :                     */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		// add_number(two, six);
		ft_modifiers_others(one_two, five_two);
	}
	return (0);
}
