/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:16 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/20 16:31:13 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	{
		ClapTrap a("Clap1");
		ScavTrap b("Scav1");
		FragTrap c("Frag1");

		a.attack("Target1");
		b.attack("Target2");
		c.attack("Target3");
		b.guardGate();
		c.highFivesGuys();
	}
	std::cout << std::endl << std::endl;
	{
		ClapTrap *ptr1 = new ScavTrap("Scav2");
		ptr1->attack("Target1");

		ClapTrap *ptr2 = new FragTrap("Frag2");
		ptr2->attack("Target1");
		
		delete ptr1;
		delete ptr2;
	}
	return (0);
}
