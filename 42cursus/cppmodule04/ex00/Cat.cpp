/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:24:36 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/21 14:44:59 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "[ Cat constructor called ]" << std::endl;
	_type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "[ Cat destructor called ]" << std::endl;
}

Cat::Cat(const Cat &origin) : Animal(origin) {}

Cat& Cat::operator= (const Cat &origin)
{
	if (this != &origin)
	{
		Animal::operator=(origin);
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
