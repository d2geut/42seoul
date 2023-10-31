/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:15:52 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/31 19:55:06 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void calculate(std::stack<int> &s, const char c)
{
	int	a;
	int	b;

	if(s.size() < 2)
		throw std::runtime_error("Error");
	b = s.top();
	s.pop();
	a = s.top();
	s.pop();
	if (c == '+')
		s.push(a + b);
	else if (c == '-')
		s.push(a - b);
	else if (c == '*')
		s.push(a * b);
	else if (c == '/' && b)
		s.push(a / b);
	else
		throw std::runtime_error("Error");
}

void rpn(const std::string &str)
{
	std::stack<int> s;
	std::stringstream ss(str);
	std::string temp;

	try
	{
		while (std::getline(ss, temp, ' '))
		{
			if (temp.empty())
				throw std::runtime_error("Error");
			char *e;
			long i = std::strtol(temp.c_str(), &e, 10);
			if (!*e)
			{
				if (0 <= i && i < 10)
					s.push(static_cast<int>(i));
				else
					throw std::runtime_error("Error");
			}
			else if (!i && !*(e + 1))
				calculate(s, *e);
			else
				throw std::runtime_error("Error");
		}
		if (s.size() != 1)
			throw std::runtime_error("Error");
		std::cout << s.top() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
}
