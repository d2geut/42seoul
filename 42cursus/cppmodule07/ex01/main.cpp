/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:02:07 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/25 18:46:31 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(const int& a)
{
	std::cout << a << std::endl;
}

void printChar(const char& a)
{
	std::cout << a << std::endl;
}

void printString(const std::string& a)
{
	std::cout << a << std::endl;
}

int main(void)
{
	int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char c[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string s[5] = {"aaa", "bbb", "ccc", "ddd", "eee"};

	::iter(i, 10, &printInt);
	::iter(c, 5, &printChar);
	::iter(s, 5, &printString);

	return 0;
}
