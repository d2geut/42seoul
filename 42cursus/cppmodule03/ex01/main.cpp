/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:16 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/19 17:59:52 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("name1");

	// a.attack("target1");
	// a.takeDamage(5);
	// a.beRepaired(1);
	// a.takeDamage(7);
	// a.beRepaired(3);
	// a.attack("target2");

	ScavTrap b("name2");
	b.attack("target1");

	return (0);
}
