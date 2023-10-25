/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:03:47 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/25 17:00:45 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator itr;

	itr = std::find(container.begin(), container.end(), value);
	if (itr == container.end())
		throw std::invalid_argument("value is not exist");
	return itr;
}

#endif