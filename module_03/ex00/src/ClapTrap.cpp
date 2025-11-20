/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:27:35 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/20 20:09:16 by ravazque         ###   ########.fr       */
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

void	ClapTrap::attack(std::string const &target)
{
	if (this->_energy_points && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacked " << target << ", causing " << this->_attack_damage << " point(s) of damage!" << std::endl;
		this->_energy_points--;
	}
	if (this->_hit_points <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	else if (!this->_energy_points)
		std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " point(s) of damage!" << std::endl;
		this->_hit_points -= amount;
	}
	else
		std::cout << "STOP! ClapTrap " << this->_name << " is already dead :(" << std::endl;
	if (this->_hit_points < 0)
		this->_hit_points = 0;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy_points)
	{
		std::cout << "ClapTrap " << this->_name << " healed " << amount << " point(s)." << std::endl;
		this->_hit_points += amount;
		this->_energy_points--;
	}
	if (this->_hit_points <= 0)
		std::cout << "Cannot repair because: ClapTrap " << this->_name << " is dead." << std::endl;
	else if (!this->_energy_points)
		std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Assignment operator for ClapTrap called." << std::endl;
	this->_name = copy.get_name();
	this->_hit_points = copy.get_hit_points();
	this->_energy_points = copy.get_energy_points();
	this->_attack_damage = copy.get_attack_damage();
	return (*this);
}

string const	&ClapTrap::get_name(void) const
{
	return(this->_name);
}

int const	&ClapTrap::get_hit_points(void) const
{
	return(this->_hit_points);
}

int const	&ClapTrap::get_energy_points(void) const
{
	return(this->_energy_points);
}

int const	&ClapTrap::get_attack_damage(void) const
{
	return(this->_attack_damage);
}

void	ClapTrap::set_name(string const &name)
{
	this->_name = name;
}

void	ClapTrap::set_hit_points(int const &value)
{
	this->_hit_points = value;
}

void	ClapTrap::set_energy_points(int const &value)
{
	this->_energy_points = value;
}

void	ClapTrap::set_attack_damage(int const &value)
{
	this->_attack_damage = value;
}
