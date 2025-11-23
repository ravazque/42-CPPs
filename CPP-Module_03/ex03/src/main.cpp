/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:27:35 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 02:02:02 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int	main(int argc, char *argv[])
{
	(void)argv;
	
	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}

	std::cout << "\033[1;35m\n### TESTING CLAPTRAP ###\n\033[0m" << std::endl;
	{
		std::cout << "\033[35mConstructing:\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("PabloMotos");

		std::cout << "\033[35mTesting:\033[0m" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("PabloMotos-Clone");
		b.beRepaired(3);
		std::cout << "\033[35mDeconstructing:\033[0m" << std::endl;
	}
	std::cout << "\033[1;33m\n\n### TESTING SCAVTRAP ###\n\033[0m" << std::endl;
	{
		std::cout << "\033[33mConstructing:\033[0m" << std::endl;
		ScavTrap c;
		ScavTrap d("Chicote");

		std::cout << "\033[33mTesting:\033[0m" << std::endl;
		c.attack("CloneTrap");
		// for (int i = 0; i < 50; i++)
		// 	c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Chicote-Clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-Clone");
		std::cout << "\033[33mDeconstructing:\033[0m" << std::endl;
	}
	std::cout << "\033[1;32m\n\n### TESTING FRAGTRAP ###\n[0m" << std::endl;
	{
		std::cout << "\033[32mConstructing:\033[0m" << std::endl;
		FragTrap e;
		FragTrap f("FernandoAlonso");

		std::cout << "\033[32mTesting:\033[0m" << std::endl;
		e.highFiveGuys();
		e.attack("some random dude");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("some random dude");
		f.highFiveGuys();
		// for(int i = 0; i < 101; i++)
		// 	f.attack("FragTrap-clone");
		std::cout << "\033[32mDeconstructing:\033[0m" << std::endl;
	}
	std::cout << "\033[1;31m\n\n### TESTING DIAMONDTRAP ###\n\033[0m" << std::endl;
	{
		std::cout << "\033[31mConstructing:\033[0m" << std::endl;
		DiamondTrap a;
		DiamondTrap b("Melendi");
		DiamondTrap c(a);

		std::cout << "\033[31mTesting:\033[0m" << std::endl;
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Melendi-Clone");
		c.whoAmI();
		std::cout << "\033[31mDeconstructing:\033[0m" << std::endl;
	}
	return (0);
}
