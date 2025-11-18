/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:15:31 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 03:19:54 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(int argc, char *argv[])
{
	Zombie zombie;
	(void)argv;
	
	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
	zombie.randomChump("Zombie 1");
	zombie.randomChump("Zombie 2");
	zombie.randomChump("Zombie 3");
	return (0);
}
