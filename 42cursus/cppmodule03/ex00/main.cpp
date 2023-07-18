/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:16 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/18 18:44:23 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("name1");
	ClapTrap b(a);
	ClapTrap c("name2");

	c = a;

	a.attack("attack1");
	b.attack("attack1");
	c.attack("attack1");

	return (0);
}
