/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:29:12 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/20 04:14:04 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>

class Span
{
	private:
		std::vector<int> m_numbers;
		bool m_is_sorted;
		unsigned int m_max_size;

	public:
		Span(void);
		Span(unsigned int N);
		Span(Span &src);

		~Span(void);

		Span &operator=(Span &src);

		void add_number(int elem);
		long int longest_span(void);
		long int shortest_span(void);

		template<typename InputIt>
		void add_numbers(InputIt start,
			InputIt end);

		class FullSpanException : public std::exception
		{
			public:
				FullSpanException();
				FullSpanException(const FullSpanException &src);

				FullSpanException &operator=(const FullSpanException &src);

				virtual ~FullSpanException() throw ();

				virtual const char *what() const throw();
		};

		class TooFewSpanElemsException : public std::exception
		{
			public:
				TooFewSpanElemsException();
				TooFewSpanElemsException(const TooFewSpanElemsException &src);

				TooFewSpanElemsException
					&operator=(const TooFewSpanElemsException &src);

				virtual ~TooFewSpanElemsException() throw ();

				virtual const char *what() const throw();
		};
};

template<typename InputIt>
void Span::add_numbers(InputIt start, InputIt end)
{
	for (InputIt it = start; it != end; ++it)
	{
		if (m_numbers.size() == m_max_size)
			throw FullSpanException();

		m_numbers.push_back(*it);
		m_is_sorted = false;
	}
}

#endif
