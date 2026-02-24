/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:44:03 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/16 16:08:19 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "=== Empty array ===" << std::endl;
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;

	std::cout << "\n=== Int array (5 elements) ===" << std::endl;
	Array<int> intArr(5);
	for (unsigned int i = 0; i < intArr.size(); i++)
		intArr[i] = i * 10;
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << "intArr[" << i << "] = " << intArr[i] << std::endl;

	std::cout << "\n=== Copy constructor ===" << std::endl;
	Array<int> copy(intArr);
	copy[0] = 999;
	std::cout << "copy[0] = " << copy[0] << std::endl;
	std::cout << "intArr[0] = " << intArr[0] << " (unchanged)" << std::endl;

	std::cout << "\n=== Assignment operator ===" << std::endl;
	Array<int> assigned;
	assigned = intArr;
	assigned[1] = 888;
	std::cout << "assigned[1] = " << assigned[1] << std::endl;
	std::cout << "intArr[1] = " << intArr[1] << " (unchanged)" << std::endl;

	std::cout << "\n=== String array ===" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "42";
	strArr[2] = "Madrid";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;

	std::cout << "\n=== Out of bounds ===" << std::endl;
	try
	{
		intArr[42] = 0;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught for index 42" << std::endl;
	}

	try
	{
		empty[0] = 0;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught for empty array" << std::endl;
	}

	return (0);
}
