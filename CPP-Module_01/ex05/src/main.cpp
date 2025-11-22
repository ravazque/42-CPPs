/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:45:56 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:29:06 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int argc, char *argv[]) 
{
	Harl harl;
	(void)argv;

	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}
	
	harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("UNKNOWN");
	
	return(0);
}
