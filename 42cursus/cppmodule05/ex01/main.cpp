/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:01:32 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/19 16:21:31 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("hanryu");
	
	std::cout << a << std::endl;
	a.decreaseGrade();
	std::cout << a << std::endl << std::endl;

	for (int i = 0; i < 149; i++)
		a.increaseGrade();
	std::cout << a << std::endl;
	a.increaseGrade();
	std::cout << a << std::endl << std::endl;

	Bureaucrat b(a);
	b.decreaseGrade();
	std::cout << b << std::endl << std::endl;

	Bureaucrat c("other");
	c = a;
	std::cout << c << std::endl;

	return (0);
}
