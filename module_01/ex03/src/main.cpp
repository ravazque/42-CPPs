/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:33:44 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 18:36:53 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

int main(int argc, char *argv[]) 
{
	(void)argv;

	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
    
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
    
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim", &club);
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
