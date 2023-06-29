/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:39:06 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/29 19:57:46 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon	&_weapon;
	HumanA(void);
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void	attack(void);
};

#endif