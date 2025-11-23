/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:11:06 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:45:34 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main(int argc, char *argv[])
{
	(void)argv;

	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}

	std::cout << "=== Test 1: Basic polymorphism with Animal/Cat/Dog ===" << std::endl;
	std::cout << "\n--- Creating objects ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n--- Checking types ---" << std::endl;
	std::cout << "meta type: " << meta->getType() << std::endl;
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;

	std::cout << "\n--- Making sounds (should use derived class methods) ---" << std::endl;
	std::cout << "meta: ";
	meta->makeSound();
	std::cout << "j (Dog): ";
	j->makeSound();
	std::cout << "i (Cat): ";
	i->makeSound();

	std::cout << "\n--- Deleting objects (virtual destructors should work) ---" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n\n=== Test 2: Array of Animals (polymorphism) ===" << std::endl;
	std::cout << "\n--- Creating array ---" << std::endl;
	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	std::cout << "\n--- Testing polymorphism in loop ---" << std::endl;
	for (int idx = 0; idx < 4; idx++)
	{
		std::cout << "Animal[" << idx << "] type: " << animals[idx]->getType() << " - ";
		animals[idx]->makeSound();
	}

	std::cout << "\n--- Deleting array ---" << std::endl;
	for (int idx = 0; idx < 4; idx++)
		delete animals[idx];

	std::cout << "\n\n=== Test 3: Copy constructor ===" << std::endl;
	std::cout << "\n--- Creating original Dog ---" << std::endl;
	Dog originalDog;
	std::cout << "\n--- Creating copy of Dog ---" << std::endl;
	Dog copyDog(originalDog);

	std::cout << "\n--- Testing both dogs ---" << std::endl;
	std::cout << "Original: ";
	originalDog.makeSound();
	std::cout << "Copy: ";
	copyDog.makeSound();

	std::cout << "\n\n=== Test 4: Assignment operator ===" << std::endl;
	std::cout << "\n--- Creating Cat and assigning to another ---" << std::endl;
	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	std::cout << "\n--- Testing both cats ---" << std::endl;
	std::cout << "Cat1: ";
	cat1.makeSound();
	std::cout << "Cat2: ";
	cat2.makeSound();

	std::cout << "\n\n=== Test 5: WRONG implementation (no virtual) ===" << std::endl;
	std::cout << "\n--- Creating WrongAnimal objects ---" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\n--- Checking types ---" << std::endl;
	std::cout << "wrongMeta type: " << wrongMeta->getType() << std::endl;
	std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;

	std::cout << "\n--- Making sounds (should use BASE class method - NO polymorphism) ---" << std::endl;
	std::cout << "wrongMeta: ";
	wrongMeta->makeSound();
	std::cout << "wrongCat: ";
	wrongCat->makeSound();
	std::cout << "(Notice: WrongCat makes WrongAnimal sound because makeSound is not virtual!)" << std::endl;

	std::cout << "\n--- Creating WrongCat directly (not through pointer) ---" << std::endl;
	WrongCat directWrongCat;
	std::cout << "directWrongCat: ";
	directWrongCat.makeSound();
	std::cout << "(This one works because we call it directly, not through base class pointer)" << std::endl;

	std::cout << "\n--- Deleting objects ---" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	std::cout << "\n=== All tests completed ===\n" << std::endl;
	return (0);
}
