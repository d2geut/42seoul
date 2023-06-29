/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:20:29 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/28 18:25:01 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int	N, std::string name)
{
	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombies[i].initZombie(name);
	return (zombies);
}
