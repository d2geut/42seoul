/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/17 06:59:36 by hanryu           ###   ########.fr       */
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
	Fixed &operator= (const Fixed &origin);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;
};

#endif