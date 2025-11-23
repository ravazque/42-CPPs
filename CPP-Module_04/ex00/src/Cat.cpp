/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:22:04 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:29:02 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Default constructor - [ Cat ]" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Copy constructor - [ Cat ]" << std::endl;
    *this = copy;
}
Cat::~Cat()
{
	std::cout << "Destructor - [ Cat ]" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Assignment operator - [ Cat ]" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void Cat::makeSound(void)const
{
	std::cout << this->getType() << ": MEOW!" << std::endl;
}
