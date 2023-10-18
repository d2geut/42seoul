/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:20 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 14:21:25 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin) : AForm(origin.getName(), 145, 137), _target(origin._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &origin)
{
	if (this != &origin)
	{
		AForm::operator=(origin);
		_target = origin._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getExegrade() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getIssigned())
		throw IsNotSignedException();

	std::string fname = _target;
	fname.append("_shrubbery");
	std::ofstream fout(fname);
	if (!fout.is_open())
	{
		std::cout << "[ file open error ]" << std::endl;
		return ;
	}
	fout << "                     . . ." << std::endl <<
		"                   .        .  .     ..    ." << std::endl <<
		"                .                 .         .  ." << std::endl <<
		"                                ." << std::endl <<
		"                               .                .." << std::endl <<
		"               .          .            .              ." << std::endl <<
		"               .            '.,        .               ." << std::endl <<
		"               .              'b      *" << std::endl <<
		"                .              '$    #.                .." << std::endl <<
		"               .    .           $:   #:               ." << std::endl <<
		"             ..      .  ..      *#  @):        .   . ." << std::endl <<
		"                          .     :@,@):   ,.**:'   ." << std::endl <<
		"              .      .,         :@@*: ..**'      .   ." << std::endl <<
		"                       '#o.    .:(@'.@*\"'  ." << std::endl <<
		"               .  .       'bq,..:,@@*'   ,*      .  ." << std::endl <<
		"                          ,p$q8,:@)'  .p*'      ." << std::endl <<
		"                   .     '  . '@@Pp@@*'    .  ." << std::endl <<
		"                    .  . ..    Y7'.'     .  ." << std::endl <<
		"                              :@):." << std::endl <<
		"                             .:@:'." << std::endl <<
		"                           .::(@:." << std::endl;
	fout.close();
	std::cout << "[ Create " << fname << " ]" << std::endl;
}
