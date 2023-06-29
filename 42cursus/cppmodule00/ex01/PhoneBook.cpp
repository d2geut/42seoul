/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:59:17 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/28 14:38:36 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) : num(0), contact()
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::Add(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "[ ADD ]" << std::endl;
	std::cout << "first name : ";
	std::cin >> first_name;
	std::cout << "last name : ";
	std::cin >> last_name;
	std::cout << "nickname : ";
	std::cin >> nickname;
	std::cout << "phone number : ";
	std::cin >> phone_number;
	std::cout << "darkest secret : ";
	std::cin >> darkest_secret;

	contact[num % 8].Replace(first_name, last_name, nickname, phone_number, darkest_secret);
	num++;

	std::cout << "[ ADD SUCCESS ]" << std::endl;
}

void	PhoneBook::Search(void)
{
	std::cout << "[ SEARCH ]" << std::endl;
	std::cout << std::setw(10) << "index";
	std::cout << " | ";
	std::cout << std::setw(10) << "first name";
	std::cout << " | ";
	std::cout << std::setw(10) << "last name";
	std::cout << " | ";
	std::cout << std::setw(10) << "nickname" << std::endl;
	
	if (num == 0)
	{
		std::cout << "[ NO CONTACT ]" << std::endl;
		return ;
	}
	if (num < 8)
	{
		for (int i = 0; i < num; i++)
			contact[i].Display(i + 1);
	}
	else
	{
		for (int i = 0; i < 8; i++)
			contact[i].Display(i + 1);
	}

	int	i;
	std::cout << "search index : ";
	std::cin >> i;
	while (std::cin.fail() || i > num || i <= 0)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		if (num < 8)
			std::cout << "[ INDEX : 1 ~ " << num << " ]" << std::endl;
		else
			std::cout << "[ INDEX : 1 ~ 8 ]" << std::endl;
		std::cout << "search index : ";
		std::cin >> i;
	}
	contact[i - 1].SearchDisplay();
	std::cout << "[ SEARCH SUCCESS ]" << std::endl;
}
