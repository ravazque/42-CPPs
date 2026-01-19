/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:00:30 by ravazque          #+#    #+#             */
/*   Updated: 2026/01/19 17:49:48 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(int argc, char *argv[])
{
	(void)argv;
	
	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
	
	std::cout << "\n=== Testing Bureaucrat Class ===" << std::endl;

	try
	{
		std::cout << "\n--- Test 1: Valid bureaucrat ---" << std::endl;
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;

		std::cout << "\n--- Test 2: Increment grade ---" << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;

		std::cout << "\n--- Test 3: Decrement grade ---" << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 4: Grade too high (0) ---" << std::endl;
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 5: Grade too low (151) ---" << std::endl;
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 6: Increment grade 1 (exception) ---" << std::endl;
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 7: Decrement grade 150 (exception) ---" << std::endl;
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 8: Copy constructor ---" << std::endl;
	Bureaucrat original("Original", 50);
	Bureaucrat copy(original);
	std::cout << "Original: " << original << std::endl;
	std::cout << "Copy: " << copy << std::endl;

	std::cout << "\n--- Test 9: Assignment operator ---" << std::endl;
	Bureaucrat a("A", 100);
	Bureaucrat b("B", 25);
	std::cout << "Before assignment: " << a << std::endl;
	a = b;
	std::cout << "After assignment: " << a << std::endl;

	std::cout << "\n=== All tests completed ===" << std::endl;
	return (0);
}
