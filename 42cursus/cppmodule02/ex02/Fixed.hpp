/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/18 04:45:59 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int	_num;
	static const int	_bits = 8;
public:
	Fixed(void);
	Fixed(int num);
	Fixed(float num);
	~Fixed(void);
	Fixed(const Fixed &origin);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;
	Fixed &operator= (const Fixed &origin);
	bool	operator> (const Fixed &other) const;
	Fixed	operator+ (const Fixed &other) const;
};

#endif