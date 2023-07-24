/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:40:50 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 18:37:02 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::~Cure(void) {}

Cure::Cure(const Cure &origin) : AMateria(origin.getType()) {}

Cure& Cure::operator= (const Cure &origin)
{
	if (this != &origin)
		AMateria::operator=(origin);
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* tmp = new Cure();

	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
