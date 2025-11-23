/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:22:04 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 03:47:02 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Constructot por defecto - [ Dog ]" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Constructor de copia - [ Dog ]" << std::endl;
    *this = copy;
}
Dog::~Dog()
{
	std::cout << "Destructor por defecto - [ Dog ]" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Operador de asignación - [ Dog ]" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void Dog::makeSound(void)const
{
	std::cout << this->getType() << ": GUAU!" << std::endl;
}
