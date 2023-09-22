/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:54:37 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/22 16:11:10 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _issigned;
	const int _signgrade;
	const int _exegrade;
	Form(void);
public:
	Form(std::string name, int signgrade, int exegrade);
	~Form(void);
	Form(const Form &origin);
	Form &operator= (const Form &origin);
	void beSigned(Bureaucrat &bureaucrat);
	std::string getName(void) const;
	bool getIssigned(void) const;
	int getSigngrade(void) const;
	int getExegrade(void) const;
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

std::ostream& operator<< (std::ostream &__out, const Form &__form);

#endif