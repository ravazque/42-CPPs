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
	this->_brain = new Brain();
	std::cout << "Default constructor - [ Cat ]" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Copy constructor - [ Cat ]" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Destructor - [ Cat ]" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Assignment operator - [ Cat ]" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return (*this);
}

void Cat::makeSound(void)const
{
	std::cout << this->getType() << ": MEOW!" << std::endl;
}

void Cat::setIdea(int index, const string &idea)
{
	this->_brain->setIdea(index, idea);
}

void Cat::getIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) != "")
			std::cout << "Idea " << i << ": " << this->_brain->getIdea(i) << std::endl;
	}
}
