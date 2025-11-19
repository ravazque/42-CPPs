/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:33:29 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:28:52 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

const std::string Weapon::getType()
{
	std::string& s = type;
	return (s);
}

void Weapon::setType( std::string s )
{
	type = s;
}
