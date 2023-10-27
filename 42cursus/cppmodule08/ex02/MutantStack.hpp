/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:15:16 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/27 14:38:24 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void) {}
	~MutantStack(void) {}
	MutantStack(const MutantStack &origin) { *this = origin; }
	MutantStack &operator=(const MutantStack &origin)
	{
		if (this != &origin)
			*this = origin;
		return (*this);
	}
	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }
	const_iterator cbegin(void) { return static_cast<const_iterator>(this->c.begin()); }
	const_iterator cend(void) { return static_cast<const_iterator>(this->c.end()); }
	reverse_iterator rbegin(void) { return this->c.rbegin(); }
	reverse_iterator rend(void) { return this->c.rend(); }
	const_reverse_iterator crbegin(void) { return static_cast<const_reverse_iterator>(this->c.rbegin()); }
	const_reverse_iterator crend(void) { return static_cast<const_reverse_iterator>(this->c.rend()); }
};

#endif