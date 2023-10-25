/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:12:38 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/24 13:19:55 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(const T &a, const T &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
const T& max(const T &a, const T &b)
{
	if (a > b)
		return a;
	return b;
}

#endif