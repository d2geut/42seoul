/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:01:32 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 17:42:25 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("hanryu", 150);
		
		std::cout << a << std::endl;
		// a.decreaseGrade();
		// std::cout << a << std::endl;

		for (int i = 0; i < 149; i++)
			a.increaseGrade();
		std::cout << a << std::endl;
		// a.increaseGrade();
		// std::cout << a << std::endl;

		Bureaucrat b(a);
		b.decreaseGrade();
		std::cout << b << std::endl;

		Bureaucrat c("other", 25);
		c = a;
		std::cout << c << std::endl;

		// Bureaucrat d("hanryu2", -1);
		// Bureaucrat d("hanryu2", 151);
		// std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
