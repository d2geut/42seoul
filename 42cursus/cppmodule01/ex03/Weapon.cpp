/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:57:04 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/29 20:31:00 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type)
{
	setType(type);
}

Weapon::~Weapon(void) {}

const std::string	&Weapon::getType(void)
{
	const std::string	&ret = _type;
	return (ret);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
