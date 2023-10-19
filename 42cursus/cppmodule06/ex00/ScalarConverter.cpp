/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:13 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/19 17:25:54 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const str)
{
	char c;
	int i;
	float f;
	double d;
	std::stringstream ss;

	ss.str(str);
	ss >> c;
	if (ss.fail())
		std::cout << "char error" << std::endl;
	ss.str(str);
	ss >> i;
	if (ss.fail())
		std::cout << "int error" << std::endl;
	ss.clear();
	ss.str(str);
	ss >> f;
	if (ss.fail())
		std::cout << "float error" << std::endl;
	ss.clear();
	ss.str(str);
	ss >> d;
	if (ss.fail())
		std::cout << "double error" << std::endl;

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed;
	std::cout.precision(std::numeric_limits<float>::max_digits10);
	std::cout << "float: " << f << std::endl;
	std::cout.precision(std::numeric_limits<double>::max_digits10 - 1);
	std::cout << "double: " << d << std::endl;
}
