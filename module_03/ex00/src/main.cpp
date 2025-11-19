/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:27:35 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 23:03:46 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main(int argc, char **argv)
{
    ClapTrap player_one("Player 1");
    ClapTrap player_two("Player 2");
    (void)argv;

	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
    return(0);
}
