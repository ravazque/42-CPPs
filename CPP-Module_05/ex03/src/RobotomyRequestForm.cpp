/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:00:30 by ravazque          #+#    #+#             */
/*   Updated: 2026/01/07 22:42:43 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "Default constructor - [ RobotomyRequestForm ]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Parametric constructor - [ RobotomyRequestForm ]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "Copy constructor - [ RobotomyRequestForm ]" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor - [ RobotomyRequestForm ]" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "Assignment operator - [ RobotomyRequestForm ]" << std::endl;
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* DRILLING NOISES * Brrrrrrr... Bzzzzzt..." << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << "!" << std::endl;
}
