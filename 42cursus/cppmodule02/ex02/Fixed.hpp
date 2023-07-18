/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/18 16:38:21 by hanryu           ###   ########.fr       */
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
	Fixed	&operator= (const Fixed &origin);
	bool	operator> (const Fixed &other) const;
	bool	operator< (const Fixed &other) const;
	bool	operator>= (const Fixed &other) const;
	bool	operator<= (const Fixed &other) const;
	bool	operator== (const Fixed &other) const;
	bool	operator!= (const Fixed &other) const;
	const Fixed	operator+ (const Fixed &other) const;
	const Fixed	operator- (const Fixed &other) const;
	const Fixed	operator* (const Fixed &other) const;
	const Fixed	operator/ (const Fixed &other) const;
	Fixed	&operator++ ();
	Fixed	operator++ (int);
	Fixed	&operator-- ();
	Fixed	operator-- (int);
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<< (std::ostream &__out, const Fixed &__fixed);

#endif