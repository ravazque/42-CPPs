/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:33:29 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 18:35:19 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string Weapon::getType()
{
	std::string& s = type;
	return (s);
}

void Weapon::setType( std::string s )
{
	type = s;
}
