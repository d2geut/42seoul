/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:56:03 by hanryu            #+#    #+#             */
/*   Updated: 2023/10/23 16:31:01 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Serializer.hpp"

int main(void)
{
	Data *a = new Data("newdata", 42);

	uintptr_t p = Serializer::serialize(a);
	std::cout << std::hex << std::showbase << p << std::endl;
	std::cout << Serializer::deserialize(p) << std::endl;
	std::cout << Serializer::deserialize(p)->getName() << std::endl;
	std::cout << std::dec << Serializer::deserialize(p)->getData() << std::endl;
	
	delete a;
	return 0;
}
