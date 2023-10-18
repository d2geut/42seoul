/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:13 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/18 14:01:03 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &origin);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &origin);
	void execute(Bureaucrat const & executor) const;
};

#endif