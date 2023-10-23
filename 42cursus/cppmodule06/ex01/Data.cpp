/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:53:40 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/23 15:08:58 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(std::string name, int data) : _name(name), _data(data) {}

Data::~Data(void) {}

Data::Data(const Data &origin) : _name(origin._name), _data(origin._data) {}

Data& Data::operator=(const Data &origin)
{
	if (this != &origin)
	{
		_name = origin._name;
		_data = origin._data;
	}
	return (*this);
}

std::string Data::getName(void) const
{
	return _name;
}

int Data::getData(void) const
{
	return _data;
}
