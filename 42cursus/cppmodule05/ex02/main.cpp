/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:01:32 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/22 16:26:13 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("hanryu", 10);
		Form form1("form1", 9, 9);
		
		std::cout << a << std::endl;
		std::cout << form1 << std::endl;
		a.signForm(form1);
		a.increaseGrade();
		a.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
