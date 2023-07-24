/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:36:04 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 16:44:52 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	~Cure(void);
	Cure(const Cure &origin);
	Cure &operator= (const Cure &origin);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif