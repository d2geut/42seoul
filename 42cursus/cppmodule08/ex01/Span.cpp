/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:06:30 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/25 21:56:27 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::~Span(void)
{
	
}

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
		throw std::range_error("already all elements stored");
	_vec.push_back(n);
}

int Span::shortestSpan(void) const
{
	
}

int Span::longestSpan(void) const
{
	
}
