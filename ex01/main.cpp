/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:49:11 by gmachado          #+#    #+#             */
/*   Updated: 2024/03/01 22:39:23 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
#include <iostream>
#include <list>

int main(void)
{
	{
		std::cout << "Tests from the subject PDF:" <<std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "Tests with empty Span class container:" <<std::endl;

	Span s;

	try
	{
		std::cout << "-> Call longestSpan():\n";
		std::cout << "--> Longest span: "<< s.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortestSpan():\n";
		std::cout << "--> Shortest span: "<< s.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Add number to Span object with empty container:\n";
		s.addNumber(42);
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "--> Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTests with Span class containing one element:"
		<<std::endl;

	Span s2(1);
	s2.addNumber(42);

	try
	{
		std::cout << "-> Call longestSpan():\n";
		std::cout << "--> Longest span: "<< s2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortestSpan():\n";
		std::cout << "--> Shortest span: "<< s2.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Add number to Span object"
			<< "with capacity for one element:\n";
		s2.addNumber(42);
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "--> Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTests with Span class containing two elements:"
		<<std::endl;

	Span s3(2);

	try
	{
		std::cout << "-> Add numbers 42 and 84:\n";
		s3.addNumber(42);
		s3.addNumber(84);
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "-> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call longestSpan():\n";
		std::cout << "--> Longest span: "<< s3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortestSpan():\n";
		std::cout << "--> Shortest span: "<< s3.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTests with Span class containing ten elements:"
		<<std::endl;

	Span s4(10);
	std::list<int> l;

	std::cout << "-> Create list with squares of numbers from one to 10:\n"
		<< "List Contents:";

	for (int i = 1; i <= 10; ++i)
	{
		l.push_back(i * i);
		std::cout << " " << i * i;
	}

	try
	{
		std::cout << "\n-> Add all numbers at once using addNumbers():\n";
		s4.addNumbers(l.begin(), l.end());
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call longestSpan():\n";
		std::cout << "--> Longest span: "<< s4.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortestSpan()\n";
		std::cout << "--> Shortest span: "<< s4.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	const unsigned int num_elems = 20000;

	std::cout << "\nTests with Span class containing " << num_elems
		<< " elements:" <<std::endl;

	Span s5(num_elems);
	std::vector<int> v;

	std::cout << "-> Create vector with odd numbers from 1 to "
		<< num_elems *2 - 3 << " along with " << (num_elems) << ":\n";

	for (unsigned int i = 1; i <= num_elems * 2 - 2; i += 2)
		v.push_back(i);

	v.push_back(num_elems);

	try
	{
		std::cout << "-> Check vector size: " << v.size() << "\n";
		std::cout << "-> Add all numbers at once using addNumbers():\n";
		s5.addNumbers(v.begin(), v.end());
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call longestSpan():\n";
		std::cout << "--> Longest span: "<< s5.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortestSpan()\n";
		std::cout << "--> Shortest span: "<< s5.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

}