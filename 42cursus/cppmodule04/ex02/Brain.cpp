/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:24:10 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 18:17:25 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) : _ideas()
{
	std::cout << "[ Brain constructor called ]" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "[ Brain destructor called ]" << std::endl;
}

Brain::Brain(const Brain &origin)
{
	std::cout << "[ Brain copy constructor called ]" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = origin._ideas[i];
}

Brain& Brain::operator= (const Brain &origin)
{
	std::cout << "[ Brain copy assignment operator called ]" << std::endl;
	if (this != &origin)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = origin._ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(const int i) const
{
	return (_ideas[i]);
}

void Brain::setIdea(std::string &idea)
{
	int i = 0;
	while (!_ideas[i].empty())
	{
		i++;
	}
	if (i != 100)
	{
		_ideas[i] = idea;
		return ;
	}
	for (i = 0; i < 99; i++)
	{
		_ideas[i] = _ideas[i + 1];
	}
	_ideas[99] = idea;
}
