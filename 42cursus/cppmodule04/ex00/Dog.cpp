/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:41:33 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/21 14:22:03 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "[ Dog constructor called ]" << std::endl;
	_type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "[ Dog destructor called ]" << std::endl;
}

Dog::Dog(const Dog &origin) : Animal(origin) {}

Dog& Dog::operator= (const Dog &origin)
{
	if (this != &origin)
	{
		Animal::operator=(origin);
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}
