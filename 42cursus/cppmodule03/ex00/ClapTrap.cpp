/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:11 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/18 19:59:21 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {}

ClapTrap::~ClapTrap(void) {}

ClapTrap::ClapTrap(const ClapTrap &origin)
{
	this->_name = origin._name;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &origin)
{
	if (this == &origin)
		return (*this);
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	(void) _hp;
	(void) _ep;
	(void) _ad;
	std::cout << _name << " : " << target << std::endl;
}
