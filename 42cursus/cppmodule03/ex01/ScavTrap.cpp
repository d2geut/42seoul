/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:14:24 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/19 18:00:54 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ Default ScavTrap constructor called ]" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ ScavTrap Destructor called ]" << std::endl;
}
