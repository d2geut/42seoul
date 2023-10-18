/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:13 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 13:58:38 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &origin);
	RobotomyRequestForm &operator= (const RobotomyRequestForm &origin);
	void execute(Bureaucrat const & executor) const;
};

#endif