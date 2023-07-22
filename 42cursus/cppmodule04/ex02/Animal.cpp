/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:09:46 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/22 14:46:21 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("")
{
	std::cout << "[ Animal constructor called ]" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "[ Animal destructor called ]" << std::endl;
}

Animal::Animal(const Animal &origin)
{
	std::cout << "[ Copy constructor called ]" << std::endl;
	*this = origin;
}

Animal& Animal::operator= (const Animal &origin)
{
	std::cout << "[ Copy assignment operator called ]" << std::endl;
	if (this != &origin)
	{
		_type = origin._type;
	}
	return (*this);
}

std::string Animal::getType(void) const
{
	return (_type);
}
