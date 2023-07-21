/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:14:15 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/20 16:55:52 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap(void);
public:
	ScavTrap(std::string name);
	virtual ~ScavTrap(void);
	ScavTrap(const ScavTrap &origin);
	ScavTrap &operator= (const ScavTrap &origin);
	virtual void attack(const std::string& target);
	void guardGate(void);
};

#endif