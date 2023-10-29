/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:36:31 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/29 23:13:55 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void isValidData(std::map<std::string, double> *data)
{
	std::ifstream fd;

	fd.open("data.csv");
	if ()
}

void isValidFile(const std::string &infile)
{
	
}

void exchange(const std::string &infile)
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
