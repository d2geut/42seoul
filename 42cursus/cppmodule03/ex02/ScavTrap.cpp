/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:14:24 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/20 15:58:14 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ ScavTrap constructor called ]" << std::endl;
	_hp = 100;
	_ep = 50;
	_ad = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ ScavTrap destructor called ]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &origin) : ClapTrap(origin) {}

ScavTrap& ScavTrap::operator= (const ScavTrap &origin)
{
	ClapTrap::operator=(origin);
	if (this == &origin)
		return (*this);

	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_hp && _ep)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
		return ;
	}
	std::cout << _name << " can't do anything" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is Gate keeper mode" << std::endl;
}
