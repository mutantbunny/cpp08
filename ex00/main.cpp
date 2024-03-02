/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 02:34:13 by gmachado          #+#    #+#             */
/*   Updated: 2024/03/02 17:03:27 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <sstream>

int main(void)
{
	std::list<int> int_list;
	std::vector<int> int_vector;
	std::deque<int> int_deque;
	const std::vector<int> const_int_vector(10, 12);

	for (size_t i = 0; i < 100; ++i)
	{
		int_list.push_back(i * 3);
		int_deque.push_back(i * 4);
		int_vector.push_back(i * 2);
	}

	// Test with std::list
	try
	{
		std::cout << "\nFind 12 in integer list:\n";
		std::list<int>::iterator it = easyfind(int_list, 12);
		std::cout << "Element returned by easyfind: " << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nFind 5 in integer list:\n";
		std::list<int>::iterator it = easyfind(int_list, 5);
		std::cout << "Element returned by easyfind: " << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n************" << std::endl;

	// Test with std::vector
	try
	{
		std::cout << "\nFind 12 in integer vector:\n";
		std::vector<int>::iterator it = easyfind(int_vector, 12);
		std::cout << "Element returned by easyfind: " << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nFind 5 in integer vector:\n";
		std::vector<int>::iterator it = easyfind(int_vector, 5);
		std::cout << "Element returned by easyfind: " << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n************" << std::endl;

	// Test with std::deque
	try
	{
		std::cout << "\nFind 12 in integer deque:\n";
		std::deque<int>::iterator it = easyfind(int_deque, 12);
		std::cout << "Element returned by easyfind: " << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nFind 5 in integer deque:\n";
		std::deque<int>::iterator it = easyfind(int_deque, 5);
		std::cout << "Element returned by easyfind: " << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n************" << std::endl;

	// Test with constant std::vector
	try
	{
		std::cout << "\nFind 12 in constant integer vector:\n";
		const std::vector<int>::const_iterator it =
			easyfind(const_int_vector, 12);
		std::cout << "Element returned by easyfind: " << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nFind 5 in constant integer vector:\n";
		const std::vector<int>::const_iterator it =
			easyfind(const_int_vector, 5);
		std::cout << "Element returned by easyfind: " << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}
