/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:13 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 13:47:16 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &origin);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &origin);
	void execute(Bureaucrat const & executor) const;
};

#endif