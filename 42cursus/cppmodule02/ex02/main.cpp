/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:25 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/18 04:47:36 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

std::ostream& operator<< (std::ostream &__out, const Fixed &__fixed)
{
	__out << __fixed.toFloat();
	return __out;
}

// int main( void ) {
// 	Fixed a;
// 	Fixed const	b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max(a, b) << std::endl;
	
// 	return 0;
// }

int	main(void)
{
	Fixed	a(10);
	Fixed	b(20.1234f);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << (a > b) << std::endl;
	std::cout << (a + b) << std::endl;

	return (0);
}
