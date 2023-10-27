/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:36:31 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/27 18:17:21 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &origin) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &origin) {}

void 

void isValidFile(const std::string &infile)
{
	
}

void BitcoinExchange::exchange(const std::string &infile)
{
	std::map<std::string, double> data;

	try
	{
		isValidData(&data);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	isValidFile(infile);
}
