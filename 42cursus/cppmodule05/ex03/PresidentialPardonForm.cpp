/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:42:48 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 14:42:48 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin) : AForm(origin.getName(), 25, 5), _target(origin._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &origin)
{
	if (this != &origin)
	{
		AForm::operator=(origin);
		_target = origin._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getExegrade() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getIssigned())
		throw IsNotSignedException();

	std::cout << "[ " << _target << " has been pardoned by Zaphod Beeblebrox ]" << std::endl;
}
