/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:21:42 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/21 04:19:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type t_container;
		typedef typename t_container::iterator iterator;
		typedef typename t_container::const_iterator const_iterator;
		typedef typename t_container::reverse_iterator reverse_iterator;
		typedef typename t_container::const_reverse_iterator
			const_reverse_iterator;

		MutantStack(void);
		MutantStack(const MutantStack &src);

		~MutantStack(void);

		MutantStack &operator=(const MutantStack &src);

		iterator begin(void);
		iterator end(void);
		const_iterator cbegin(void) const;
		const_iterator cend(void) const;
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
		const_reverse_iterator crbegin(void) const;
		const_reverse_iterator crend(void) const;
};

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() { }

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) :
	std::stack<T>(src) { }

template<typename T>
MutantStack<T>::~MutantStack(void) { }

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &src)
{
	std::stack<T>::operator=(src);
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator
	MutantStack<T>::crbegin(void) const
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator
	MutantStack<T>::crend(void) const
{
	return this->c.rend();
}

#endif
