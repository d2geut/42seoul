/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:13:52 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/25 21:52:16 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

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
	template <typename T>
	void addNumber(typename T::iterator start, typename T::iterator end);
	int	shortestSpan(void) const;
	int longestSpan(void) const;
};

template <typename T>
void addNumber(typename T::iterator start, typename T::iterator end)
{
	
}

#endif