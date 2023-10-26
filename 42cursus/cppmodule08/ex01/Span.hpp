/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:13:52 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/26 18:29:08 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <typeinfo>
#include <climits>
#include <iterator>

class Span
{
private:
	std::vector<int> _vec;
	unsigned int _n;
	Span(void);
public:
	Span(unsigned int n);
	~Span(void);
	Span(const Span &origin);
	Span &operator=(const Span &origin);
	void addNumber(int n);
	template <typename InputIt>
	void addNumber(InputIt start, InputIt end);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
};

template <typename InputIt>
void Span::addNumber(InputIt start, InputIt end)
{
	if (typeid(int) != typeid(typename std::iterator_traits<InputIt>::value_type))
		throw std::runtime_error("data is not integer");
	for (InputIt itr = start; itr != end; itr++)
		addNumber(*itr);
}

#endif
