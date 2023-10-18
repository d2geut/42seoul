/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:43:55 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 17:18:49 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern &origin)
{
	(void)origin;
}

Intern& Intern::operator= (const Intern &origin)
{
	(void)origin;
	return *this;
}

template <class T>
AForm* Intern::createForm(std::string target)
{
	return new T(target);
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm* (*ptr[3])(std::string);
	std::string str[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	ptr[0] = &createForm<ShrubberyCreationForm>;
	ptr[1] = &createForm<RobotomyRequestForm>;
	ptr[2] = &createForm<PresidentialPardonForm>;

	for (int i = 0; i < 3; i++)
	{
		if (str[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ptr[i](target);
		}
	}
	throw IsNotFormException();
}

const char* Intern::IsNotFormException::what() const throw()
{
	return ("Is Not Form");
}
