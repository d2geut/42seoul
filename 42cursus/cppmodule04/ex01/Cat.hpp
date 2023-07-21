/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:24:38 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/21 17:22:42 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &origin);
	Cat &operator= (const Cat &origin);
	void makeSound(void) const;
	void showIdea(void) const;
	void setIdea(std::string idea);
};

#endif