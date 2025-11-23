/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:11:06 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:27:03 by ravazque         ###   ########.fr       */
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

	std::cout << "=== Testing correct polymorphism with Animal/Cat/Dog ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nType: " << j->getType() << std::endl;
	std::cout << "Type: " << i->getType() << std::endl;

	std::cout << "\n--- Making sounds (should use derived class methods) ---" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n--- Deleting objects ---" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== Testing WRONG implementation (no virtual) ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\nType: " << wrongCat->getType() << std::endl;

	std::cout << "\n--- Making sounds (should use base class method) ---" << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "\n--- Deleting objects ---" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return (0);
}
