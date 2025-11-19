/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:14:13 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:27:14 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

int	main(int argc, char **argv)
{
	phoneBook	pb;
	string		input;
	(void)argv;

	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
	system("clear");
	std::cout << "Welcome to your amazing phonebook software!" << std::endl;
	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, input) || std::cin.eof())
		{
			std::cout << std::endl << "Fast exit detected. Exiting..." << std::endl;
			break ;
		}
		if (!input.compare("ADD"))
			pb.add_contact();
		else if (!input.compare("SEARCH"))
			pb.search_contact();
		else if (!input.compare("EXIT"))
		{
			std::cout << "Bye bye!" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid argument." << std::endl;
	}
	return (0);
}
