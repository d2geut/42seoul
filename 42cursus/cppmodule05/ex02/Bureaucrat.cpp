/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:02:01 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/22 16:10:45 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat &origin) : _name(origin._name), _grade(origin._grade) {}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat &origin)
{
	if (this != &origin)
	{
		_grade = origin._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::increaseGrade(void)
{
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream& operator<< (std::ostream &__out, const Bureaucrat &__bureaucrat)
{
	__out << __bureaucrat.getName() << ", bureaucrat grade " << __bureaucrat.getGrade() << ".";
	return (__out);
}
