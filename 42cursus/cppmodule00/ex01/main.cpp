/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:07:05 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/27 17:11:49 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	str;
	
	std::cout << "[ START ]" << std::endl;
	while (1)
	{
		std::cout << "[ Enter Command : ADD | SEARCH | EXIT ]" << std::endl;
		std::cin >> str;
		if (str == "ADD")
			phonebook.Add();
		else if (str == "SEARCH")
			phonebook.Search();
		else if (str == "EXIT")
			break ;
	}
	std::cout << "[ EXIT ]" << std::endl;
	return (0);
}
