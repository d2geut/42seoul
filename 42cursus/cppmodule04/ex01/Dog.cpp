/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:41:33 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/22 13:22:52 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "[ Dog constructor called ]" << std::endl;
	_type = "Dog";
	_brain = new Brain;
}

Dog::~Dog(void)
{
	std::cout << "[ Dog destructor called ]" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &origin)
{
	*this = origin;
}

Dog& Dog::operator= (const Dog &origin)
{
	if (this != &origin)
	{
		delete _brain;
		Animal::operator=(origin);
		_brain = new Brain(*origin._brain);
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}

void Dog::showIdea(void) const
{
	std::string str;

	for (int i = 0; i < 100; i++)
	{
		str = _brain->getIdea(i);
		if (str.empty())
			break ;
		std::cout << str << std::endl;
	}
}

void Dog::setIdea(std::string idea)
{
	_brain->setIdea(idea);
}
