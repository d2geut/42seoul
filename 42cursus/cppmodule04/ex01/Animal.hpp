/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:14:34 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/21 17:43:00 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string _type;
public:
	Animal(void);
	virtual ~Animal(void);
	Animal(const Animal &origin);
	Animal &operator= (const Animal &origin);
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif
