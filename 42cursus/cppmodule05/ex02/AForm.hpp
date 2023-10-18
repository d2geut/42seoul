/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:54:37 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 12:32:23 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _issigned;
	const int _signgrade;
	const int _exegrade;
	AForm(void);
public:
	AForm(std::string name, int signgrade, int exegrade);
	virtual ~AForm(void);
	AForm(const AForm &origin);
	AForm &operator= (const AForm &origin);
	void beSigned(Bureaucrat &bureaucrat);
	std::string getName(void) const;
	bool getIssigned(void) const;
	int getSigngrade(void) const;
	int getExegrade(void) const;
	virtual void execute(Bureaucrat const & executor) const = 0;
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
	class IsNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream &__out, const AForm &__aform);

#endif