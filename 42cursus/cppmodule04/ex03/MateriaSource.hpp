/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAteriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:38:36 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 15:39:50 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_m[4];
public:
	MateriaSource(void);
	~MateriaSource(void);
	MateriaSource(const MateriaSource &origin);
	MateriaSource &operator= (const MateriaSource &origin);
	void learnMateria(AMateria *);
	AMateria* createMateria(std::string const &type);
};

#endif