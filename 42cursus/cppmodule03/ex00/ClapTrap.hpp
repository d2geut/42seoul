/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:03 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/18 18:44:50 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string _name;
	int _hp;
	int _ep;
	int _ad;
public:
	ClapTrap(std::string name);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &origin);
	ClapTrap &operator= (const ClapTrap &origin);
	void attack(const std::string& target);
};

#endif