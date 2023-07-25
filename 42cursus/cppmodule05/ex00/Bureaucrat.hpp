/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:01:49 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/25 18:48:30 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat &origin);
	Bureaucrat &operator= (const Bureaucrat &origin);
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

#endif