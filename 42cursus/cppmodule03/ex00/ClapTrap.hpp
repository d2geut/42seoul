/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:03 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/19 13:42:01 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _ad;
public:
	ClapTrap(std::string name);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &origin);
	ClapTrap &operator= (const ClapTrap &origin);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif