/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:08:28 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/28 17:16:38 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie*	zombie;

	zombie = newZombie("Zombie1");
	randomChump("Zombie2");
	zombie->announce();
	delete zombie;
	zombie = 0;

	return (0);
}
