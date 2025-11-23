/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:22:04 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:29:02 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Default constructor - [ Animal ]" << std::endl;
}
Animal::Animal(const Animal &copy)
{
    std::cout << "Copy constructor - [ Animal ]" << std::endl;
    *this = copy;
}
Animal::~Animal()
{
	std::cout << "Destructor - [ Animal ]" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Assignment operator - [ Animal ]" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void Animal::makeSound(void)const
{
	std::cout << "This animal doesn't make any sound." << std::endl;
}

string	Animal::getType(void)const
{
	return (this->_type);
}
