/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:26:40 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/30 07:33:06 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	std::string	level;

	if (argc != 2)
	{
		std::cout << "Use: ./harlFilter <level>" << std::endl;
		return (0);
	}

	level = argv[1];
	harl.complain(level);
	return (0);
}