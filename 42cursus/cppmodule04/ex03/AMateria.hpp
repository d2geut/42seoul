/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:03:22 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 16:44:01 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
private:
	AMateria(void);
protected:
	std::string _type;
public:
	AMateria(std::string const &type);
	virtual ~AMateria(void);
	AMateria(const AMateria &origin);
	AMateria &operator= (const AMateria &origin);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif