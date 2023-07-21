/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:21:28 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/21 17:09:53 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain(void);
	~Brain(void);
	Brain(const Brain &origin);
	Brain &operator= (const Brain &origin);
	std::string getIdea(int i) const;
	void setIdea(std::string &idea);
};

#endif