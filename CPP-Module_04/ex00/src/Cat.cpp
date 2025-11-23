/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:22:04 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 03:47:05 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Constructot por defecto - [ Cat ]" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Constructor de copia - [ Cat ]" << std::endl;
    *this = copy;
}
Cat::~Cat()
{
	std::cout << "Destructor por defecto - [ Cat ]" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Operador de asignación - [ Cat ]" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void Cat::makeSound(void)const
{
	std::cout << this->getType() << ": MIAU!" << std::endl;
}
