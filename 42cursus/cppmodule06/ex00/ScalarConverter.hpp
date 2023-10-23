/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:31:00 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/23 16:42:13 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter(void);
	~ScalarConverter(void);
	ScalarConverter(const ScalarConverter &origin);
	ScalarConverter &operator= (const ScalarConverter &origin);
	static void allImpossible(void);
	static void oneChar(const char c);
	static void value(const float f, const double d);
public:
	static void convert(std::string str);
};

#endif