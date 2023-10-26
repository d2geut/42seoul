/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:06:30 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/26 17:56:57 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::~Span(void) {}

Span::Span(const Span &origin) : _n(origin._n)
{
	_vec = origin._vec;
}

Span& Span::operator=(const Span &origin)
{
	if (this != &origin)
	{
		_n = origin._n;
		_vec = origin._vec;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_n <= _vec.size())
		throw std::runtime_error("already all elements stored");
	_vec.push_back(n);
}

unsigned int Span::shortestSpan(void) const
{
	if (_vec.size() <= 2)
		throw std::runtime_error("no numbers stored, or only one");
	
	std::vector<int> temp = _vec;
	long span = LONG_MAX;

	std::sort(temp.begin(), temp.end());
	for (std::vector<int>::iterator itr = temp.begin(); itr != temp.end(); itr++)
	{
		if (itr == temp.begin())
			continue ;
		if (*itr - *(itr - 1) < span)
			span = *itr - *(itr - 1);
	}
	return static_cast<unsigned int>(span);
}

unsigned int Span::longestSpan(void) const
{
	if (_vec.size() <= 2)
		throw std::runtime_error("no numbers stored, or only one");
	return (*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end()));
}
