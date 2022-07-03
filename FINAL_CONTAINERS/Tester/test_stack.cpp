#include "../containers/stack.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <cstddef>
#include <stack>
#include <type_traits>
#include <vector>

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
void	add_number(T1 &std, T2 &ft) {

	for (int i = 1 ; i <= 10 ; ++i) {

			std.push(i);
			ft.push(i);
	}
}

template <class T1, class T2>
void ft_basic_stack(T1 &std, T2 &ft) {

	std::stack<int> test;
	ft::stack<int> test_two;

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

	std::cout << STD_GREEN << "----------------STD/FT : ------------------" << std::endl;

	if (std.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;
	
	if (ft.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;
	
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*    PUSH / POP :  */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << FT_BLUE << "----------------ADDING NUMBERS : ------------------" << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;


	std.push(42);
	std.push(6);
	std.push(1);
	std.push(911);
	std.push(2);
	std.push(3);
	std.push(90);


	std.pop();
	std.pop();
	std.pop();
	std.pop();
	std.pop();
	std.pop();

	if (std.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	ft.push(42);
	ft.push(6);
	ft.push(1);
	ft.push(911);
	ft.push(2);
	ft.push(3);
	ft.push(90);

	ft.pop();
	ft.pop();
	ft.pop();
	ft.pop();
	ft.pop();
	ft.pop();
	

	if (ft.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;


	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*       TOP :      */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	std::cout << std.top() << std::endl;

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	std::cout << ft.top() << std::endl;

	
	
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*       OTHERS :   */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /*  Size again:     */"	<< std::endl;
	std::cout <<  SUB_SUB_HEAD << "						      /* ---------------- */"	<< std::endl;
	std::cout << std::endl;

	std::cout << STD_GREEN << "----------------STD : ------------------" << std::endl;

	print_size(std);

	std::cout << FT_BLUE << "----------------FT : ------------------" << std::endl;

	print_size(ft);



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

/* ************************************************************************** */
/*                                	   OTHERS :                               */
/* ************************************************************************** */

int main() {
	

	std::cout <<  HEAD << "		   	/* ========================================================================= */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                                                    	     */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                STACK :                                    */"	<< std::endl;
	std::cout <<  HEAD << "		   	/*                                                                     	     */"	<< std::endl;
	std::cout <<  HEAD << "		   	/* ========================================================================= */"	<< std::endl;
	std::cout << std::endl;
	{
		std::stack<int> one;

		ft::stack<int> two;

		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /*                         BASICS :                        */"	<< std::endl;
		std::cout <<  SUB_HEAD << "				 /* ******************************************************* */"	<< std::endl;
		std::cout << std::endl;

		ft_basic_stack(one, two);


	}
	return (0);
}
