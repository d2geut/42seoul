/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:46:29 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 18:41:45 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _m() {}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_m[i])
			break;
		delete _m[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &origin) : _m()
{
	for (int i = 0; i < 4; i++)
	{
		if (origin._m[i])
			_m[i] = origin._m[i]->clone();
	}
}

MateriaSource& MateriaSource::operator= (const MateriaSource &origin)
{
	if (this != &origin)
	{
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

void MateriaSource::learnMateria(AMateria *m)
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

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_m[i] && _m[i]->getType() == type)
			return (_m[i]->clone());
	}
	return (0);
}
