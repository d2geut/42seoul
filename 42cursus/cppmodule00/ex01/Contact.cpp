/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:22:51 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/28 14:38:19 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::Replace(std::string _first_name, std::string _last_name, std::string _nickname, std::string _phone_number, std::string _darkest_secret)
{
	first_name = _first_name;
	last_name = _last_name;
	nickname = _nickname;
	phone_number = _phone_number;
	darkest_secret = _darkest_secret;
}

void	Contact::Display(int i)
{
	std::cout << std::setw(10) << i;
	std::cout << " | ";
	if (first_name.length() <= 10)
		std::cout << std::setw(10) << first_name;
	else
		std::cout << first_name.substr(0,9) << '.';
	std::cout << " | ";
	if (last_name.length() <= 10)
		std::cout << std::setw(10) << last_name;
	else
		std::cout << last_name.substr(0,9) << '.';
	std::cout << " | ";
	if (nickname.length() <= 10)
		std::cout << std::setw(10) << nickname;
	else
		std::cout << nickname.substr(0,9) << '.';
	std::cout << std::endl;
}

void	Contact::SearchDisplay(void)
{
	std::cout << "first name : " << first_name << std::endl;
	std::cout << "last name : " << last_name << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
	std::cout << "phone number : " << phone_number << std::endl;
	std::cout << "darkest secret : " << darkest_secret << std::endl;
}
