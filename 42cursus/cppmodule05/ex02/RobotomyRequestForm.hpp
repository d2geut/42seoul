/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:13 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/08 23:56:12 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(std::string name);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &origin);
	RobotomyRequestForm &operator= (const RobotomyRequestForm &origin);
	void execute(Bureaucrat const & executor) const;
};

#endif