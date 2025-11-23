/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 05:02:00 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 06:13:24 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Character.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/MateriaSource.hpp"

int	main(int argc, char *argv[])
{
	(void)argv;
	
	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
	
	std::cout << "===== SUBJECT TESTS =====" << std::endl << std::endl;

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

	std::cout << std::endl << "===== ADDITIONAL TESTS =====" << std::endl << std::endl;

	std::cout << "--- Test 1: Equip full inventory ---" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());

	ICharacter* player = new Character("player");

	AMateria* m1 = src2->createMateria("ice");
	AMateria* m2 = src2->createMateria("cure");
	AMateria* m3 = src2->createMateria("ice");
	AMateria* m4 = src2->createMateria("cure");
	AMateria* m5 = src2->createMateria("ice");

	player->equip(m1);
	player->equip(m2);
	player->equip(m3);
	player->equip(m4);
	player->equip(m5); // This should be ignored (inventory full)

	ICharacter* target = new Character("target");
	player->use(0, *target);
	player->use(1, *target);
	player->use(2, *target);
	player->use(3, *target);

	delete m5; // Delete the 5th materia that wasn't equipped
	delete target;
	delete player;
	delete src2;

	std::cout << std::endl << "--- Test 2: Unequip and use ---" << std::endl;
	IMateriaSource* src3 = new MateriaSource();
	src3->learnMateria(new Ice());

	ICharacter* char1 = new Character("char1");
	ICharacter* enemy = new Character("enemy");

	AMateria* ice = src3->createMateria("ice");
	char1->equip(ice);
	char1->use(0, *enemy); // Should work

	char1->unequip(0); // Unequip but don't delete
	char1->use(0, *enemy); // Should do nothing (slot is empty)

	delete ice; // Now we manually delete the unequipped materia
	delete enemy;
	delete char1;
	delete src3;

	std::cout << std::endl << "--- Test 3: Deep copy test ---" << std::endl;
	Character original("original");

	IMateriaSource* src4 = new MateriaSource();
	src4->learnMateria(new Ice());
	src4->learnMateria(new Cure());

	AMateria* ice2 = src4->createMateria("ice");
	AMateria* cure2 = src4->createMateria("cure");

	original.equip(ice2);
	original.equip(cure2);

	std::cout << "Creating copy..." << std::endl;
	Character copy(original);

	ICharacter* dummy = new Character("dummy");

	std::cout << "Original uses materias:" << std::endl;
	original.use(0, *dummy);
	original.use(1, *dummy);

	std::cout << "Copy uses materias:" << std::endl;
	copy.use(0, *dummy);
	copy.use(1, *dummy);

	delete dummy;
	delete src4;

	std::cout << std::endl << "--- Test 4: Unknown materia type ---" << std::endl;
	IMateriaSource* src5 = new MateriaSource();
	src5->learnMateria(new Ice());

	AMateria* unknown = src5->createMateria("fire"); // Should return NULL
	if (unknown == NULL)
		std::cout << "Fire materia not found (expected)" << std::endl;
	else
		delete unknown;

	delete src5;

	std::cout << std::endl << "--- Test 5: MateriaSource learn limit ---" << std::endl;
	IMateriaSource* src6 = new MateriaSource();

	src6->learnMateria(new Ice());
	src6->learnMateria(new Cure());
	src6->learnMateria(new Ice());
	src6->learnMateria(new Cure());

	AMateria* extra = new Ice();
	src6->learnMateria(extra); // Should be ignored (full)
	delete extra; // We need to delete it manually since it wasn't learned

	AMateria* test1 = src6->createMateria("ice");
	AMateria* test2 = src6->createMateria("cure");

	if (test1 != NULL)
	{
		std::cout << "Created materia type: " << test1->getType() << std::endl;
		delete test1;
	}
	if (test2 != NULL)
	{
		std::cout << "Created materia type: " << test2->getType() << std::endl;
		delete test2;
	}

	delete src6;

	std::cout << std::endl << "===== ALL TESTS COMPLETED =====" << std::endl;

	return 0;
}
