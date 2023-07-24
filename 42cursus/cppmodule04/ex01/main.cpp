/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:37:49 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 18:14:56 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete i;
		delete j;
	}
	std::cout << std::endl;
	{
		Animal * arr[100];

		for (int i = 0; i < 100; i++)
		{
			if (i % 2)
				arr[i] = new Dog();
			else
				arr[i] = new Cat();
		}
		
		for (int i = 0; i < 100; i++)
		{
			arr[i]->makeSound();
			delete arr[i];
		}
	}
	std::cout << std::endl;
	{
		Cat* c = new Cat();
		
		for (int i = 0; i < 10; i++)
		{
			if (i % 2)
				c->setIdea("sleep");
			else
				c->setIdea("eat");
		}
		Cat* d = new Cat();
		*d = *c;

		Cat* e = new Cat(*c);

		std::cout << "== c ==" << std::endl;
		c->showIdea();
		std::cout << "== d ==" << std::endl;
		d->showIdea();
		std::cout << "== e ==" << std::endl;
		e->showIdea();
		delete c;
		std::cout << "== d after delete c ==" << std::endl;
		d->showIdea();
		std::cout << "== e after delete c ==" << std::endl;
		e->showIdea();
		delete d;
		delete e;
	}
	std::cout << std::endl;
	{
		Dog* d = new Dog();

		for (int i = 0; i < 100; i++)
		{
			if (i % 2)
				d->setIdea("sleep");
			else
				d->setIdea("eat");
		}
		d->setIdea("think");
		d->showIdea();
		delete d;
	}
	system("leaks a.out");
	return 0;
}