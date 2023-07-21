/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:14:15 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/20 16:58:24 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap(void);
public:
	FragTrap(std::string name);
	virtual ~FragTrap(void);
	FragTrap(const FragTrap &origin);
	FragTrap &operator= (const FragTrap &origin);
	virtual void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif