/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:16 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/20 16:56:20 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
		ClapTrap a("Clap1");
		ScavTrap b("Scav1");

		a.attack("Target1");
		b.attack("Target2");
		b.takeDamage(10);
		b.beRepaired(5);
		b.guardGate();
	}
	std::cout << std::endl << std::endl;
	{
		ClapTrap *ptr = new ScavTrap("Scav2");
		ptr->attack("Target1");
		
		delete ptr;
	}
	return (0);
}
