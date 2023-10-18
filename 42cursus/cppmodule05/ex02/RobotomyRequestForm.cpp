/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:42:39 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 14:42:40 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin) : AForm(origin.getName(), 72, 45), _target(origin._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &origin)
{
	if (this != &origin)
	{
		AForm::operator=(origin);
		_target = origin._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getExegrade() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getIssigned())
		throw IsNotSignedException();

	std::cout << "[ D D D D D D ]" << std::endl;
	if (rand() % 2)
		std::cout << "[ " << _target << " has been robotomized ]" << std::endl;
	else
		std::cout << "[ Robotomy failed ]" << std::endl;
}
