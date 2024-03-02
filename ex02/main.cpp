/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:21:47 by gmachado          #+#    #+#             */
/*   Updated: 2024/03/01 22:45:42 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

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
	{
		std::cout << "Test example from subject PDF using MutantStack:"
			<< std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << "\nSame test using a list (should return the same result):"
			<< std::endl;

		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int, std::list<int> > s(lst);
	}


	std::cout << "\nTest iterators:" << std::endl;

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

	std::cout << "\nTest if copies are deep:" << std::endl;
	std::cout << "-> Pop last element from ms and push 42." << std::endl;
	ms.pop();
	ms.push(42);

	std::cout << "\n-> ms after pop + push:"
		<< std::endl << "--> ";
	print_contents(ms);

	std::cout << "\n-> ms2 should remain unchanged:"
		<< std::endl << "--> ";
	print_contents(ms2);

	std::cout << "\n-> ms3 should remain unchanged:"
		<< std::endl << "--> ";
	print_contents(ms3);

	std::cout << std::endl;
}