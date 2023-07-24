/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:04:11 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 17:48:26 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor(void) : _idx(0), _m() {}

Floor::~Floor(void)
{
	for (int i = 0; i < _idx; i++)
	{
		if (_m[i])
			delete _m[i];
	}
}

Floor::Floor(const Floor &origin) : _m()
{
	for (int i = 0; i < 100; i++)
	{
		if (origin._m[i])
			_m[i] = origin._m[i]->clone();
	}
}

Floor& Floor::operator= (const Floor &origin)
{
	if (this != &origin)
	{
		for (int i = 0; i < 100; i++)
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

void Floor::addMateria(AMateria *m)
{
	if (!m)
		return ;
	if (_idx >= 100)
	{
		for (int i = 0; i < _idx; i++)
		{
			if (_m[i])
				delete _m[i];
		}
		_idx = 0;
	}
	_m[_idx++] = m;
}
