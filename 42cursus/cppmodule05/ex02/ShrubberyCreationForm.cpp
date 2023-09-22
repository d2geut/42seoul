/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:20 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/22 18:22:11 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin) : AForm(origin.getName(), 145, 137) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &origin)
{

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

}
