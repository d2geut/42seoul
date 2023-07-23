/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:36:04 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 04:44:12 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	~Ice(void);
	Ice(const Ice &origin);
	Ice &operator= (const Ice &origin);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif