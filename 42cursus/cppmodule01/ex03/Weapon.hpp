/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:03:41 by hanryu            #+#    #+#             */
/*   Updated: 2023/06/29 19:01:37 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	const std::string&	getType(void);
	void	setType(std::string type);
};

#endif
