/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:32:13 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/09 00:12:42 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(std::string name);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &origin);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &origin);
	void execute(Bureaucrat const & executor) const;
};

#endif