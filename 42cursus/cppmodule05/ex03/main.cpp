/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:01:32 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 17:26:19 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand(time(NULL));
	AForm *form1 = 0;
	AForm *form2 = 0;
	AForm *form3 = 0;
	AForm *form4 = 0;

	try
	{
		Intern someintern;
		Bureaucrat a("hanryu", 5);
		
		form1 = someintern.makeForm("shrubbery creation", "one");
		form2 = someintern.makeForm("robotomy request", "two");
		form3 = someintern.makeForm("presidential pardon", "three");
		// form4 = someintern.makeForm("error", "four");

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;
		// std::cout << *form4 << std::endl;

		a.signForm(*form1);
		a.signForm(*form2);
		a.signForm(*form3);

		a.executeForm(*form1);

		a.executeForm(*form2);
		a.executeForm(*form2);
		a.executeForm(*form2);
		a.executeForm(*form2);
		a.executeForm(*form2);

		a.executeForm(*form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete form1;
	delete form2;
	delete form3;
	delete form4;
	return (0);
}
