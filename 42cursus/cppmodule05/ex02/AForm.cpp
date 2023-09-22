/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:54:45 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/22 17:27:15 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signgrade, int exegrade) : _name(name), _signgrade(signgrade), _exegrade(exegrade)
{
	if (_signgrade < 1 || _exegrade < 1)
		throw GradeTooHighException();
	else if (_signgrade > 150 || _exegrade > 150)
		throw GradeTooLowException();
	_issigned = false;
}

AForm::~AForm(void) {}

AForm::AForm(const AForm &origin) : _name(origin._name), _signgrade(origin._signgrade), _exegrade(origin._exegrade) {}

AForm& AForm::operator= (const AForm &origin)
{
	if (this != &origin)
	{
		_issigned = origin._issigned;
	}
	return (*this);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_signgrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	_issigned = true;
}

std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getIssigned(void) const
{
	return (_issigned);
}

int AForm::getSigngrade(void) const
{
	return (_signgrade);
}
int AForm::getExegrade(void) const
{
	return (_exegrade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream& operator<< (std::ostream &__out, const AForm &__aform)
{
	__out << __aform.getName() << ", form signed " << std::boolalpha << __aform.getIssigned() << ", form sign grade " << __aform.getSigngrade() << ", form execute grade " << __aform.getExegrade() << ".";
	return (__out);
}

