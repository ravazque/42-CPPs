/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 02:16:19 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 02:35:41 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cout << "Please enter a positive number greater than 0." << std::endl;
		return (NULL);
	}

	Zombie *zombies = new Zombie[N];
	int i = 0;
	while (i < N)
	{
        zombies[i].setName(name);
		i++;
	}
    return (zombies);
}
