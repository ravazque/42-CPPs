/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:00:30 by ravazque          #+#    #+#             */
/*   Updated: 2026/01/07 20:01:05 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 130);
		ShrubberyCreationForm shrub("home");
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robot("Bender");
		std::cout << alice << std::endl;
		std::cout << robot << std::endl;
		alice.signForm(robot);
		alice.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing execution without signing ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Ford Prefect");
		std::cout << boss << std::endl;
		std::cout << pardon << std::endl;
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing execution with low grade ===" << std::endl;
	try
	{
		Bureaucrat highSign("HighSign", 20);
		Bureaucrat lowExec("LowExec", 50);
		PresidentialPardonForm pardon("Trillian");
		std::cout << highSign << std::endl;
		std::cout << lowExec << std::endl;
		std::cout << pardon << std::endl;
		highSign.signForm(pardon);
		lowExec.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return (0);
}
