/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:14:56 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/28 14:36:33 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact(void);
	~Contact(void);
	void	Replace(std::string _first_name, std::string _last_name, std::string _nickname, std::string _phone_number, std::string _darkest_secret);
	void	Display(int i);
	void	SearchDisplay(void);
};

#endif
