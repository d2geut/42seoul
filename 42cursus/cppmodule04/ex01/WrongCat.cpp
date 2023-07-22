/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:24:36 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/21 14:44:59 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : Animal()
{
	std::cout << "[ WrongCat constructor called ]" << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "[ WrongCat destructor called ]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &origin) : Animal(origin) {}

WrongCat& WrongCat::operator= (const WrongCat &origin)
{
	if (this != &origin)
	{
		Animal::operator=(origin);
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Woem Woem" << std::endl;
}
