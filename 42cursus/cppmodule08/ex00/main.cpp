/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:21:03 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/26 18:03:01 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);		
	}

	try
	{
		std::vector<int>::iterator itr = ::easyfind(v, 4);
		std::cout << *itr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::deque<int>::iterator itr2 = ::easyfind(d, 3);
		std::cout << *itr2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::iterator itr3 = ::easyfind(l, 2);
		std::cout << *itr3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
