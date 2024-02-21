/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:21:47 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 04:22:53 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

static void print_contents(MutantStack<int> &ms)
{
	std::cout << "Contents:";

	if ( ms.begin() == ms.end())
	{
		std::cout << " (empty)" << std::endl;
		return;
	}

	for(MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << std::endl;
}

int main(void)
{
	std::cout << "Test iterators:" << std::endl;

	std::cout << "-> Create empty MutantStack ms." << std::endl;
	MutantStack<int> ms;
	std::cout << "-> Fill MutantStack ms with 10 values.\n--> Contents:";

	for (int i = 0; i < 10; ++i)
	{
		ms.push(i * i);
		std::cout << " " << i * i;
	}

	std::cout << "\n-> Element pointed by iterator begin(): "
		<< *ms.begin() << std::endl;
	std::cout << "-> Element pointed by iterator end() - 1: "
		<< *(ms.end() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator cbegin(): "
		<< *ms.cbegin() << std::endl;
	std::cout << "-> Element pointed by iterator cend() - 1: "
		<< *(ms.cend() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator rbegin(): "
		<< *ms.rbegin() << std::endl;
	std::cout << "-> Element pointed by iterator rend() - 1: "
		<< *(ms.rend() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator crbegin(): "
		<< *ms.crbegin() << std::endl;
	std::cout << "-> Element pointed by iterator crend() - 1: "
		<< *(ms.crend() - 1) << std::endl;

	std::cout << "\nTest incrementing and decrementing an iterator:"
		<< std::endl;

	std::cout << "-> Create iterator initialized to ms.begin()." << std::endl;
	MutantStack<int>::iterator it = ms.begin();
	std::cout << "-> Element pointed by iterator it: "
		<< *it << std::endl;

	std::cout << "-> Pre-increment iterator it. "
		<< "Element pointed by iterator it: "
		<< *(++it) << std::endl;
	std::cout << "--> After pre-incrementing iterator it. "
		<< "Element pointed by iterator it: "
		<< *(it) << std::endl;

	std::cout << "-> Post-increment iterator it. "
		<< "Element pointed by iterator it: "
		<< *(it++) << std::endl;
	std::cout << "--> After post-incrementing iterator it. "
		<< "Element pointed by iterator it: "
		<< *(it) << std::endl;

	std::cout << "-> Pre-decrement iterator it. "
		<< "Element pointed by iterator it: "
		<< *(--it) << std::endl;
	std::cout << "--> After pre-decrementing iterator it. "
		<< "Element pointed by iterator it: "
		<< *(it) << std::endl;

	std::cout << "-> Post-decrement iterator it. "
		<< "Element pointed by iterator it: "
		<< *(it--) << std::endl;
	std::cout << "--> After post-decrementing iterator it. "
		<< "Element pointed by iterator it: "
		<< *(it) << std::endl;

	std::cout
		<< "\nTest iterators after pushing number 100 to MutantStack ms:"
		<< std::endl;

	ms.push(100);
	std::cout << "-> Element pointed by iterator begin(): "
		<< *ms.begin() << std::endl;
	std::cout << "-> Element pointed by iterator end() - 1: "
		<< *(ms.end() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator cbegin(): "
		<< *ms.cbegin() << std::endl;
	std::cout << "-> Element pointed by iterator cend() - 1: "
		<< *(ms.cend() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator rbegin(): "
		<< *ms.rbegin() << std::endl;
	std::cout << "-> Element pointed by iterator rend() - 1: "
		<< *(ms.rend() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator crbegin(): "
		<< *ms.crbegin() << std::endl;
	std::cout << "-> Element pointed by iterator crend() - 1: "
		<< *(ms.crend() - 1) << std::endl;

	std::cout
		<< "\nTest iterators after popping two elements from MutantStack ms:"
		<< std::endl;

	ms.pop();
	ms.pop();

	std::cout << "-> Element pointed by iterator begin(): "
		<< *ms.begin() << std::endl;
	std::cout << "-> Element pointed by iterator end() - 1: "
		<< *(ms.end() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator cbegin(): "
		<< *ms.cbegin() << std::endl;
	std::cout << "-> Element pointed by iterator cend() - 1: "
		<< *(ms.cend() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator rbegin(): "
		<< *ms.rbegin() << std::endl;
	std::cout << "-> Element pointed by iterator rend() - 1: "
		<< *(ms.rend() - 1) << std::endl;
	std::cout << "-> Element pointed by iterator crbegin(): "
		<< *ms.crbegin() << std::endl;
	std::cout << "-> Element pointed by iterator crend() - 1: "
		<< *(ms.crend() - 1) << std::endl;

	std::cout << "\nTest MutantStack assignment operator:" << std::endl;

	std::cout << "-> Create empty MutantStack ms2." << std::endl << "--> ";
	MutantStack<int> ms2;
	print_contents(ms2);
	std::cout << "-> Assign ms to ms2." << std::endl << "--> ";
	ms2 = ms;
	print_contents(ms2);

	std::cout << "\nTest MutantStack copy constructor:" << std::endl;

	std::cout << "-> Create MutantStack ms3 by copying ms."
		<< std::endl << "--> ";
	MutantStack<int> ms3(ms);
	print_contents(ms2);
}