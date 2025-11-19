/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:27:35 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 23:11:57 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap" << this->_name << " created. - [ with default constructor ]" << std::endl;
}

ClapTrap::ClapTrap(string const &name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap" << this->_name << " created." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap" << this->_name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap" << this->_name << " copied." << std::endl;
	*this = copy;
}

void ClapTrap::attack(const string& target)
{
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing" << this->_attack_damage << "points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " took " << amount << " point(s) of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " healed " << amount << " point(s)." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Assignment operator for ClapTrap called." << std::endl;
	// this->_name = copy.get_name();
	// this->_hit_points = copy.get_hit_points();
	// this->_energy_points = copy.get_energy_points();
	// this->_attack_damage = copy.get_attack_damage();
	return (*this);
}
