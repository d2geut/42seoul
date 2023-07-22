/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:41:26 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/22 13:22:47 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog(void);
	~Dog(void);
	Dog(const Dog &origin);
	Dog &operator= (const Dog &origin);
	void makeSound(void) const;
	void showIdea(void) const;
	void setIdea(std::string idea);
};

#endif