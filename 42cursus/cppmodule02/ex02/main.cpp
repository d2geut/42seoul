/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:11:25 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/18 16:38:08 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	
	return 0;
}

// int	main(void)
// {
// 	Fixed	a(10);
// 	Fixed	b(20.1234f);
// 	Fixed	c;

// 	std::cout << "a : " << a << std::endl;
// 	std::cout << "b : " << b << std::endl;

// 	std::cout << "a > b : " << (a > b) << std::endl;
// 	std::cout << "a < b : " << (a < b) << std::endl;
// 	std::cout << "a >= b : " << (a >= b) << std::endl;
// 	std::cout << "a <= b : " << (a <= b) << std::endl;
// 	std::cout << "a == b : " << (a == b) << std::endl;
// 	std::cout << "a != b : " << (a != b) << std::endl;
// 	std::cout << "a + b : " << (a + b) << std::endl;
// 	std::cout << "a - b : " << (a - b) << std::endl;
// 	std::cout << "a * b : " << (a * b) << std::endl;
// 	std::cout << "a / b : " << (a / b) << std::endl;

// 	c = a++;
// 	std::cout << "a++ c : " << a  << " " << c << std::endl;
// 	c = ++a;
// 	std::cout << "++a c : " << a  << " " << c << std::endl;
// 	c = a--;
// 	std::cout << "a-- c : " << a  << " " << c << std::endl;
// 	c = --a;
// 	std::cout << "--a c : " << a  << " " << c << std::endl;

// 	std::cout << "a b max : " << Fixed::max(a, b) << std::endl;
// 	std::cout << "a b min : " << Fixed::min(a, b) << std::endl;

// 	return (0);
// }
