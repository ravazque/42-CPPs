/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:31:40 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:34:32 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor - [ Brain ]" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy constructor - [ Brain ]" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Destructor - [ Brain ]" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Assignment operator - [ Brain ]" << std::endl;
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}

void Brain::setIdea(int index, const string &idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return "";
}
