/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 02:01:55 by gmachado          #+#    #+#             */
/*   Updated: 2024/03/01 16:09:12 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &haystack, int needle)
{
	typename T::iterator it =
		std::find(haystack.begin(), haystack.end(), needle);

	if (it == haystack.end())
		throw std::runtime_error("Value not found");

	return it;
}

template<typename T>
typename T::const_iterator easyfind(const T &haystack, int needle)
{
	const typename T::const_iterator it =
		std::find(haystack.begin(), haystack.end(), needle);

	if (it == haystack.end())
		throw std::runtime_error("Value not found");

	return it;
}

#endif
