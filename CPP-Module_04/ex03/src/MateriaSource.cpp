/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 05:01:00 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 05:01:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
		this->_templates[i] = NULL;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] != NULL)
			delete this->_templates[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return (*this);

	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] != NULL)
		{
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
		if (src._templates[i] != NULL)
			this->_templates[i] = src._templates[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] == NULL)
		{
			this->_templates[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] != NULL && this->_templates[i]->getType() == type)
			return (this->_templates[i]->clone());
	}
	return (NULL);
}
