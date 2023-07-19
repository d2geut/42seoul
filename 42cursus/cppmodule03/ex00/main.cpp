/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:16 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/19 15:05:48 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("name1");

	a.attack("target1");
	a.takeDamage(5);
	a.beRepaired(1);
	a.takeDamage(7);
	a.beRepaired(3);
	a.attack("target2");

	ClapTrap b(a);
	b.beRepaired(1);

	return (0);
}
