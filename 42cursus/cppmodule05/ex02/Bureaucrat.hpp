/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:01:49 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/22 15:25:41 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

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
	void signForm(Form &form);
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