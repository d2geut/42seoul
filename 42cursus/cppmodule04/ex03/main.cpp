/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:15:33 by hanryu            #+#    #+#             */
/*   Updated: 2023/07/24 20:21:22 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"

int main()
{
	{
		// 기본 테스트
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		// 복사 생성자 & 대입 연산자 오버로딩 테스트
		Floor* floor = new Floor();
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp;
		Character* a = new Character("a");

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		tmp = src->createMateria("ice");
		a->equip(tmp);
		tmp = src->createMateria("cure");
		a->equip(tmp);

		Character* b = new Character("b");
		*b = *a;
		delete a;
		ICharacter* bob = new Character("bob");
		b->use(0, *bob);
		b->use(1, *bob);
		std::cout << std::endl;

		Character* c = new Character(*b);
		tmp = b->getMateria(0);
		floor->addMateria(tmp);
		b->unequip(0);
		tmp = src->createMateria("cure");
		b->equip(tmp);
		b->use(0, *bob);
		b->use(1, *bob);
		c->use(0, *bob);
		c->use(1, *bob);
		c->use(2, *bob);

		delete bob;
		delete b;
		delete c;
		delete floor;
		delete src;
	}
	system("leaks a.out");
	return 0;
}
