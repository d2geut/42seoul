/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:51:15 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/28 14:37:04 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	int		num;
	Contact	contact[8];
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	Add(void);
	void	Search(void);
};

#endif
