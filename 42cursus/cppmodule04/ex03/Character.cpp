/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:03:32 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 17:33:19 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : _name(name), _m() {}

Character::~Character(void) {}

Character::Character(const Character &origin) : _name(origin._name), _m()
{
	for (int i = 0; i < 4; i++)
	{
		if (origin._m[i])
			_m[i] = origin._m[i]->clone();
	}
}

Character& Character::operator= (const Character &origin)
{
	if (this != &origin)
	{
		_name = origin._name;
		for (int i = 0; i < 4; i++)
		{
			if (_m[i])
			{
				delete _m[i];
				_m[i] = 0;
			}
			if (origin._m[i])
				_m[i] = origin._m[i]->clone();
		}
	}
	return (*this);
}

std::string const& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_m[i])
		{
			_m[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	_m[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (_m[idx])
		_m[idx]->use(target);
}

AMateria* Character::getMateria(int idx) const
{
	return (_m[idx]);
}
