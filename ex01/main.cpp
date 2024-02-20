/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:49:11 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/20 04:30:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
#include <iostream>
#include <list>

int main(void)
{
	std::cout << "Tests with empty Span class container:" <<std::endl;

	Span s;

	try
	{
		std::cout << "-> Call longest_span():\n";
		std::cout << "--> Longest span: "<< s.longest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortest_span():\n";
		std::cout << "--> Shortest span: "<< s.shortest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Add number to Span object with empty container:\n";
		s.add_number(42);
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "--> Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTests with Span class containing one element:"
		<<std::endl;

	Span s2(1);
	s2.add_number(42);

	try
	{
		std::cout << "-> Call longest_span():\n";
		std::cout << "--> Longest span: "<< s2.longest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortest_span():\n";
		std::cout << "--> Shortest span: "<< s2.shortest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Add number to Span object"
			<< "with capacity for one element:\n";
		s2.add_number(42);
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
		s3.add_number(42);
		s3.add_number(84);
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "-> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call longest_span():\n";
		std::cout << "--> Longest span: "<< s3.longest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortest_span():\n";
		std::cout << "--> Shortest span: "<< s3.shortest_span() << std::endl;
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
		std::cout << "-> Add all numbers at once using add_numbers():\n";
		s4.add_numbers(l.begin(), l.end());
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call longest_span():\n";
		std::cout << "--> Longest span: "<< s4.longest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortest_span()\n";
		std::cout << "--> Shortest span: "<< s4.shortest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTests with Span class containing 10 000 elements:"
		<<std::endl;

	const unsigned int num_elems = 10000;
	Span s5(num_elems);
	std::vector<int> v;

	std::cout << "-> Create vector with odd numbers from 1 to "
		<< num_elems *2 - 3 << " along with " << (num_elems) << ":\n";

	for (unsigned int i = 1; i <= num_elems * 2 - 2; i += 2)
		v.push_back(i);

	v.push_back(num_elems);

	try
	{
		std::cout << "-> Add all numbers at once using add_numbers():\n";
		s5.add_numbers(v.begin(), v.end());
		std::cout << "--> Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call longest_span():\n";
		std::cout << "--> Longest span: "<< s5.longest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "-> Call shortest_span()\n";
		std::cout << "--> Shortest span: "<< s5.shortest_span() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\n--> Exception caught: " << e.what() << std::endl;
	}

}