/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:00:30 by ravazque          #+#    #+#             */
/*   Updated: 2026/01/07 22:42:43 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "Default constructor - [ PresidentialPardonForm ]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Parametric constructor - [ PresidentialPardonForm ]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "Copy constructor - [ PresidentialPardonForm ]" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor - [ PresidentialPardonForm ]" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "Assignment operator - [ PresidentialPardonForm ]" << std::endl;
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
