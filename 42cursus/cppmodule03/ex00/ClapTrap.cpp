/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:11 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/20 16:54:22 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "[ Constructor called ]" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ Destructor called ]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &origin)
{
	std::cout << "[ Copy constructor called ]" << std::endl;
	*this = origin;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &origin)
{
	std::cout << "[ Copy assignment operator called ]" << std::endl;
	if (this == &origin)
		return (*this);
	_name = origin._name;
	_hp = origin._hp;
	_ep = origin._ep;
	_ad = origin._ad;

	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hp && _ep)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
		return ;
	}
	std::cout << "ClapTrap " << _name << " can't do anything" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " damages" << std::endl;
	if (_hp > amount)
		_hp -= amount;
	else
		_hp = 0;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp && _ep)
	{
		std::cout << "ClapTrap " << _name << " repair " << amount << " hp" << std::endl;
		_hp += amount;
		_ep--;
		return ;
	}
	std::cout << "ClapTrap " << _name << " can't do anything" << std::endl;
}
