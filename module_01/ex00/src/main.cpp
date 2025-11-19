/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:15:31 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:38:19 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(int argc, char *argv[])
{
	(void)argv;
	
	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
	
	randomChump("Static Zombie");

	Zombie *zombie = newZombie("Dinamic Zombie");
	zombie->announce();
	delete zombie;

	return (0);
}
