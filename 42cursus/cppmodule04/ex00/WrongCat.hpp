/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:24:38 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/21 14:49:20 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal
{
public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat &origin);
	WrongCat &operator= (const WrongCat &origin);
	void makeSound(void) const;
};

#endif