/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:33:34 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:28:45 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " have no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanA " << name << " destroyed" << std::endl;
}
