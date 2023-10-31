/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:36:31 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/31 19:50:29 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int isValidDate(std::string str)
{
	const char *c = str.c_str();
	char *e;

	long year = std::strtol(c, &e, 10);
	if (*e != '-')
		throw std::runtime_error("bad input");
	long month = std::strtol(e + 1, &e, 10);
	if (*e != '-')
		throw std::runtime_error("bad input");
	long day = std::strtol(e + 1, &e, 10);
	if (*e)
		throw std::runtime_error("bad input");
	if (year > 0 && year < 10000 && month > 0 && day > 0)
	{
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (1 <= day && day <= 31))
			return (year * 10000 + month * 100 + day);
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && (1 <= day && day <= 30))
			return (year * 10000 + month * 100 + day);
		else if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100))
			{
				if (1 <= day && day <= 29)
					return (year * 10000 + month * 100 + day);
			}
			else
			{
				if (1 <= day && day <= 28)
					return (year * 10000 + month * 100 + day);
			}
		}
	}
	throw std::runtime_error("bad input");
}

static void isValidData(std::map<int, double> &data)
{
	std::ifstream fd;

	fd.open("data.csv");
	if (!fd.is_open())
		throw std::runtime_error("could not open file");

	std::string str;
	std::getline(fd, str);
	if (str != "date,exchange_rate")
	{
		fd.close();
		throw std::runtime_error("file format error");
	}
	while (1)
	{
		std::getline(fd, str);
		if (fd.eof())
			break ;
		std::stringstream ss(str);
		std::string temp;
		std::string temp2;
		std::getline(ss, temp, ',');
		ss >> temp2;
		if (temp2.empty())
		{
			fd.close();
			throw std::runtime_error("file format error");
		}
		char *e;
		double rate = std::strtod(temp2.c_str(), &e);
		if (*e || rate < 0)
		{
			fd.close();
			throw std::runtime_error("file format error");
		}
		try
		{
			data[isValidDate(temp)] = rate;
		}
		catch(const std::exception& e)
		{
			fd.close();
			throw std::runtime_error(e.what());
		}
	}
	fd.close();
}

static void searchMap(int key, double value, std::map<int, double> &data)
{
	std::map<int, double>::iterator itr;

	itr = data.upper_bound(key);
	if (itr == data.begin())
		throw std::runtime_error("no data");
	std::cout << std::setfill('0') << std::setw(4) << key / 10000;
	std::cout << "-" << std::setw(2) << (key % 10000) / 100;
	std::cout << "-" << std::setw(2) << (key % 100);
	std::cout << " => " << value << " = " << value * (--itr)->second << std::endl;
}

static void isValidFile(const std::string &infile, std::map<int, double> &data)
{
	std::ifstream fd;

	fd.open(infile);
	if (!fd.is_open())
		throw std::runtime_error("could not open file");
	
	std::string str;
	std::getline(fd, str);
	if (str != "date | value")
	{
		fd.close();
		throw std::runtime_error("file format error");
	}
	
	while (1)
	{
		std::getline(fd, str);
		if (fd.eof())
			break ;
		try
		{
			std::string temp;
			std::string temp2;
			size_t pos = 0;
			if ((pos = str.find(" | ")) != std::string::npos)
			{
				temp = str.substr(0, pos);
				temp2 = str.substr(pos + 3, str.length());
				int key = isValidDate(temp);
				char *e;
				double value = std::strtod(temp2.c_str(), &e);
				if (*e || temp2.empty())
					throw std::runtime_error("bad input");
				else if (value < 0)
					throw std::runtime_error("not a positive number");
				else if (value > 1000)
					throw std::runtime_error("too large a number");
				searchMap(key, value, data);
			}
			else
				throw std::runtime_error("bad input");
		}
		catch(const std::exception& e)
		{
			if (!std::strcmp(e.what(), "bad input"))
				std::cerr << "Error: " << e.what() << " => " << str << std::endl;
			else
				std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	fd.close();
}

void exchange(const std::string &infile)
{
	std::map<int, double> data;

	try
	{
		isValidData(data);
		isValidFile(infile, data);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
