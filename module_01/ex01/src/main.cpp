/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:15:31 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 12:54:44 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(int argc, char *argv[])
{
	int N = 5;
	(void)argv;

	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}

	Zombie *zombies = Zombie::zombieHorde(N, "Zombie");

	if (zombies == NULL)
		return (1);

	while (N != 0)
	{
		zombies[N - 1].announce();
		N -= 1;
	}
	delete[] zombies;
	return (0);
}
