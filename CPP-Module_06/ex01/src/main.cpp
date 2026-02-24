/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:12:04 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/13 14:52:28 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}

	Data original;
	original.name = "test";
	original.value = 42;

	std::cout << "\n=== Testing Serializer Class ===" << std::endl;

	std::cout << "\n--- Original Data ---" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "Name:    " << original.name << std::endl;
	std::cout << "Value:   " << original.value << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\n--- After serialize ---" << std::endl;
	std::cout << "Raw (uintptr_t): " << raw << std::endl;

	Data *deserialized = Serializer::deserialize(raw);
	std::cout << "\n--- After deserialize ---" << std::endl;
	std::cout << "Address: " << deserialized << std::endl;
	std::cout << "Name:    " << deserialized->name << std::endl;
	std::cout << "Value:   " << deserialized->value << std::endl;

	std::cout << "\n--- Comparison ---" << std::endl;
	if (deserialized == &original)
		std::cout << "Pointers match!" << std::endl;
	else
		std::cout << "Pointers do NOT match!" << std::endl;

	std::cout << std::endl;
	return (0);
}
