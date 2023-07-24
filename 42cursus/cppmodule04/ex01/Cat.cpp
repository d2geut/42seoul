/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:24:36 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 18:13:43 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "[ Cat constructor called ]" << std::endl;
	_type = "Cat";
	_brain = new Brain;
}

Cat::~Cat(void)
{
	std::cout << "[ Cat destructor called ]" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &origin) : Animal(origin)
{
	_brain = new Brain(*origin._brain);
}

Cat& Cat::operator= (const Cat &origin)
{
	if (this != &origin)
	{
		delete _brain;
		Animal::operator=(origin);
		_brain = new Brain(*origin._brain);
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}

void Cat::showIdea(void) const
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

void Cat::setIdea(std::string idea)
{
	_brain->setIdea(idea);
}
