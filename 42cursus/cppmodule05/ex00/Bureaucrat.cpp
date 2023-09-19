/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:02:01 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/19 16:10:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) {}

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
	try
	{
		if (_grade <= 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decreaseGrade(void)
{
	try
	{
		if (_grade >= 150)
			throw GradeTooLowException();
		_grade++;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
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
