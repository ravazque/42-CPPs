/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:00:30 by ravazque          #+#    #+#             */
/*   Updated: 2026/01/07 22:42:43 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{
	std::cout << "Default constructor - [ Intern ]" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Copy constructor - [ Intern ]" << std::endl;
	(void)copy;
}

Intern::~Intern()
{
	std::cout << "Destructor - [ Intern ]" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Assignment operator - [ Intern ]" << std::endl;
	(void)src;
	return (*this);
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(Intern::*formCreators[3])(const std::string &) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}
	std::cout << "Error: Form \"" << formName << "\" does not exist." << std::endl;
	return (NULL);
}
