/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:21:01 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:29:02 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "Default constructor - [ WrongAnimal ]" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "Copy constructor - [ WrongAnimal ]" << std::endl;
    *this = copy;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor - [ WrongAnimal ]" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Assignment operator - [ WrongAnimal ]" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void WrongAnimal::makeSound(void)const
{
	std::cout << "This WrongAnimal doesn't make any sound." << std::endl;
}

string	WrongAnimal::getType(void)const
{
	return (this->_type);
}
