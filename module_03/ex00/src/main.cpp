/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:27:35 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/20 20:06:07 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

static void	player_one_rundown(void)
{
	ClapTrap player_one("PlayerOne");

	player_one.attack("Bob");
	player_one.attack("Chris");
	player_one.attack("Diana");
	player_one.attack("Elisa");
	player_one.attack("Fred");
	player_one.attack("Gemma");
	player_one.attack("Henry");
	player_one.attack("Isabella");
	player_one.attack("Jack");
	player_one.attack("Kevin");
	player_one.attack("Laura");
	player_one.attack("Mike");
}

static void	player_two_rundown(void)
{
	ClapTrap	player_two("PlayerTwo");

	while (player_two.get_hit_points())
	{
		player_two.takeDamage(2);
		player_two.beRepaired(2);
	}
	player_two.takeDamage(1);
}

int	main(int argc, char **argv)
{
    (void)argv;

	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
	
	std::cout << std::endl << std::endl << "Performing Player's One rundown..." << std::endl << std::endl;
	player_one_rundown();
	std::cout << std::endl << std::endl << "Performing Player's Two rundown..." << std::endl << std::endl;
	player_two_rundown();

    return(0);
}
