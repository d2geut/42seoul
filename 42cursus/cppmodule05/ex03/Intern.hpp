/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:43:52 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 17:17:44 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	Intern(void);
	~Intern(void);
	Intern(const Intern &origin);
	Intern &operator= (const Intern &origin);
	AForm* makeForm(std::string const &name, std::string const &target);
	template <class T>
	static AForm* createForm(std::string target);
	class IsNotFormException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif