/* **********************************hanryu**************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:20 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/08 23:56:26 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 72, 45) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin) : AForm(origin.getName(), 145, 137) {}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &origin)
{
	if (this != &origin)
		AForm::operator=(origin);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getExegrade() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << "D D D D D" << std::endl;
}
