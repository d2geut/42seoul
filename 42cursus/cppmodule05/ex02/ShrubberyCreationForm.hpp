/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:13 by hanryu            #+#    #+#             */
/*   Updated: 2023/09/22 17:41:51 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(std::string name);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &origin);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &origin);
	void execute(Bureaucrat const & executor) const;
};

#endif