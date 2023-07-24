/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:52:25 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 16:43:55 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria(void) {}

AMateria::AMateria(const AMateria &origin)
{
	_type = origin._type;
}

AMateria& AMateria::operator= (const AMateria &origin)
{
	if (this != &origin)
	{
		_type = origin._type;
	}
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
}
