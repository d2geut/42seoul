/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:33 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 16:14:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

class Floor
{
private:
	int _idx;
	AMateria *_m[100];
public:
	Floor(void);
	~Floor(void);
	Floor(const Floor &origin);
	Floor &operator= (const Floor &origin);
	void addMateria(AMateria *m);
};

#endif