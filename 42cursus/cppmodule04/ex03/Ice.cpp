/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:40:50 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 18:37:24 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::~Ice(void) {}

Ice::Ice(const Ice &origin) : AMateria(origin.getType()) {}

Ice& Ice::operator= (const Ice &origin)
{
	if (this != &origin)
		AMateria::operator=(origin);
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* tmp = new Ice();

	return (tmp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
