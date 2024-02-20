/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:37:44 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/20 04:16:21 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : m_numbers(), m_is_sorted(false), m_max_size(0) { }

Span::Span(unsigned int N) : m_numbers(), m_is_sorted(false), m_max_size(N) { }

Span::Span(Span &src) { *this = src; }

Span::~Span(void) { }

Span &Span::operator=(Span &src)
{
	if (this == &src)
		return *this;

	m_numbers.assign(src.m_numbers.begin(), src.m_numbers.end());
	m_numbers = src.m_numbers;
	m_is_sorted = src.m_is_sorted;

	return *this;
}

void Span::add_number(int elem)
{
	if (m_numbers.size() == m_max_size)
		throw FullSpanException();

	m_numbers.push_back(elem);
	m_is_sorted = false;
}

long int Span::longest_span(void)
{
	if (m_numbers.size() < 2)
		throw TooFewSpanElemsException();

	if (! m_is_sorted)
	{
		std::sort(m_numbers.begin(), m_numbers.end());
		m_is_sorted = true;
	}

	return *(m_numbers.end() - 1) - *(m_numbers.begin());
}

long int Span::shortest_span(void)
{

	if (m_numbers.size() < 2)
		throw TooFewSpanElemsException();

	if (! m_is_sorted)
	{
		std::sort(m_numbers.begin(), m_numbers.end());
		m_is_sorted = true;
	}

	long int min_distance = std::numeric_limits<int>::max();
	std::vector<int>::iterator it = m_numbers.begin();
	std::vector<int>::iterator end_it = m_numbers.end() - 1;

	for (it = m_numbers.begin(); it < end_it; ++it)
	{
		long int cur_distance = *(it + 1) - *it;

		if (cur_distance == 0)
			return 0;

		if (cur_distance < 0)
			cur_distance = -cur_distance;

		if (cur_distance < min_distance)
			min_distance = cur_distance;
	}

	return min_distance;
}

Span::FullSpanException::FullSpanException() { }

Span::FullSpanException::FullSpanException(const FullSpanException &src)
{
	(void) src;
}

Span::FullSpanException
	&Span::FullSpanException::operator=(const Span::FullSpanException &src)
{
	(void) src;
	return *this;
}

Span::FullSpanException::~FullSpanException()  throw () { }

const char *Span::FullSpanException::what() const throw()
{
	return "Number storage is already full, can't add another number.";
}

Span::TooFewSpanElemsException::TooFewSpanElemsException() { }

Span::TooFewSpanElemsException::TooFewSpanElemsException(
	const Span::TooFewSpanElemsException &src)
{
	(void) src;
}

Span::TooFewSpanElemsException &Span::TooFewSpanElemsException::operator=(
	const Span::TooFewSpanElemsException &src)
{
	(void) src;
	return *this;
}

Span::TooFewSpanElemsException::~TooFewSpanElemsException() throw () { }

const char *Span::TooFewSpanElemsException::what() const throw()
{
	return "There must be at least two numbers in storage before "
		"calculating a span.";
}