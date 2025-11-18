/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:45:47 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 18:29:09 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR]\nThis is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain( string level )
{
    int		i = 0;

    string levels[] =
	{
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    while (i < 4)
	{
        if (levels[i] == level)
            break ;
        i++;
    }
	switch (i)
	{
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
        break;
	}
	if (i == 4)
	    std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
}
