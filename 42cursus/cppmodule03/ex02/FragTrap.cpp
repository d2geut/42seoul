/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:14:24 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/20 16:17:33 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ FragTrap constructor called ]" << std::endl;
	_hp = 100;
	_ep = 100;
	_ad = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[ FragTrap destructor called ]" << std::endl;
}

FragTrap::FragTrap(const FragTrap &origin) : ClapTrap(origin) {}

FragTrap& FragTrap::operator= (const FragTrap &origin)
{
	ClapTrap::operator=(origin);
	if (this == &origin)
		return (*this);

	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (_hp && _ep)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
		return ;
	}
	std::cout << _name << " can't do anything" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " high fives" << std::endl;
}
