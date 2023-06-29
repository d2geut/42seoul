/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:17:02 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/29 15:23:48 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int	N, std::string name);

int	main(void)
{
	Zombie*	zombies;
	int		N;

	N = 5;

	zombies = zombieHorde(N, "zom");
	for (int i = 0; i < N; i++)
		zombies[i].announce();

	delete[] zombies;
	return (0);
}
