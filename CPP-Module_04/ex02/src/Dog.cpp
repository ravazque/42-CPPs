/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:22:04 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:29:02 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Default constructor - [ Dog ]" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Copy constructor - [ Dog ]" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Destructor - [ Dog ]" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Assignment operator - [ Dog ]" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return (*this);
}

void Dog::makeSound(void)const
{
	std::cout << this->getType() << ": WOOF WOOF!" << std::endl;
}

void Dog::setIdea(int index, const string &idea)
{
	this->_brain->setIdea(index, idea);
}

void Dog::getIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) != "")
			std::cout << "Idea " << i << ": " << this->_brain->getIdea(i) << std::endl;
	}
}
