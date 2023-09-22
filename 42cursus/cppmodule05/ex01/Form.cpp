/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:54:45 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/22 16:25:46 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signgrade, int exegrade) : _name(name), _signgrade(signgrade), _exegrade(exegrade)
{
	if (_signgrade < 1 || _exegrade < 1)
		throw GradeTooHighException();
	else if (_signgrade > 150 || _exegrade > 150)
		throw GradeTooLowException();
	_issigned = false;
}

Form::~Form(void) {}

Form::Form(const Form &origin) : _name(origin._name), _signgrade(origin._signgrade), _exegrade(origin._exegrade) {}

Form& Form::operator= (const Form &origin)
{
	if (this != &origin)
	{
		_issigned = origin._issigned;
	}
	return (*this);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_signgrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	_issigned = true;
}

std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getIssigned(void) const
{
	return (_issigned);
}

int Form::getSigngrade(void) const
{
	return (_signgrade);
}
int Form::getExegrade(void) const
{
	return (_exegrade);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream& operator<< (std::ostream &__out, const Form &__form)
{
	__out << __form.getName() << ", form signed " << std::boolalpha << __form.getIssigned() << ", form sign grade " << __form.getSigngrade() << ", form execute grade " << __form.getExegrade() << ".";
	return (__out);
}

