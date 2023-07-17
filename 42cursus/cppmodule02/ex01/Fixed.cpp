/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:33 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/18 04:05:24 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	_num = num << _bits;
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
	_num = roundf(num * (1 << _bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	_num = origin.getRawBits();
}

Fixed& Fixed::operator= (const Fixed &origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origin)
		return *this;
	_num = origin.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void) const
{
	return _num;
}

void	Fixed::setRawBits(int const raw)
{
	_num = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_num / (1 << _bits));
}

int	Fixed::toInt(void) const
{
	return (_num >> _bits);
}
