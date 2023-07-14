/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:58:44 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/14 13:14:43 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	std::ifstream	fin;
	std::ofstream	fout;
	std::string		str;
	std::string		s1;
	std::string		s2;

	if (argc != 4 || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Use: a.out filename s1 s2" << std::endl;
		return (0);
	}
	s1 = argv[2];
	s2 = argv[3];

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		std::cout << "file open error" << std::endl;
		return (1);
	}

	std::string	outfile = argv[1];
	outfile.append(".replace");
	fout.open(outfile);
	if (!fout.is_open())
	{
		std::cout << "file open error" << std::endl;
		fin.close();
		return (1);
	}

	while (std::getline(fin, str))
	{
		std::size_t	n = str.find(s1);
		while (n != std::string::npos)
		{
			str.erase(n, s1.length());
			str.insert(n, s2);
			n = str.find(s1);
		}
		fout << str << std::endl;
	}
	fin.close();
	fout.close();
	return (0);	
}
