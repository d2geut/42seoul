/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:01:49 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 12:24:54 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	Bureaucrat(void);
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat &origin);
	Bureaucrat &operator= (const Bureaucrat &origin);
	std::string getName(void) const;
	int getGrade(void) const;
	void increaseGrade(void);
	void decreaseGrade(void);
	void signForm(AForm &form);
	void executeForm(AForm const &form);
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream &__out, const Bureaucrat &__bureaucrat);

#endif