/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:13 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/20 18:26:29 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void allImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void oneChar(const char c)
{
	if ((9 <= c && c <= 13) || (32 <= c && c <= 126))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::showpoint << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	std::cout << std::noshowpoint;
}

static void value(float f, double d)
{
	char c;

	if (d > CHAR_MAX || d < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else
	{
		c = static_cast<char>(d);
		if ((9 <= c && c <= 13) || (32 <= c && c <= 126))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << std::showpoint;
	if (f == HUGE_VALF || f == -HUGE_VALF)
		std::cout << "float: impossible" << std::endl;
	else
	{
		if (std::abs(f - static_cast<int>(f)) < 1e-16 || (f > 10000 && f < 1000000))
		{
			std::cout << std::fixed;
			std::cout.precision(1);
		}
		std::cout << "float: " << f << "f" << std::endl;
	}
	if (d == HUGE_VAL || d == -HUGE_VAL)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
	std::cout << std::noshowpoint;
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::convert(std::string const str)
{
	float f;
	double d;

	const char *s = str.c_str();
	char *ed = const_cast<char *>(str.c_str()) + str.size();
	char *ef = const_cast<char *>(str.c_str()) + str.size();

	d = std::strtod(s, &ed);
	f = std::strtof(s, &ef);
	if (d == 0)
	{
		if (!*ed || (str.size() != 1 && *ed == 'f' && !*(ed + 1)))
			d = 0.0;
		else if (str.size() != 1)
			return allImpossible();
		else
			return oneChar(*ed);
	}
	else if (std::isnan(d))
		return allImpossible();
	if (*ed && !(*ed == 'f' && !*(ed + 1)))
		allImpossible();
	else
		value(f, d);
	// std::cout << "char: " << c << std::endl;
	// std::cout << "int: " << i << std::endl;
	// std::cout << std::fixed;
	// std::cout.precision(std::numeric_limits<float>::max_digits10);
	// std::cout << "float: " << f << std::endl;
	// std::cout.precision(std::numeric_limits<double>::max_digits10 - 1);
	// std::cout << "double: " << d << std::endl;
}
