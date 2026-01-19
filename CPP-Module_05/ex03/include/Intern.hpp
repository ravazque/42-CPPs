/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:01:11 by ravazque          #+#    #+#             */
/*   Updated: 2026/01/07 22:54:31 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:

		AForm	*createShrubbery(const std::string &target);
		AForm	*createRobotomy(const std::string &target);
		AForm	*createPresidential(const std::string &target);

	public:

		Intern();
		Intern(const Intern &copy);
		~Intern();

		Intern &operator=(const Intern &src);

		AForm	*makeForm(const std::string &formName, const std::string &target);

};

#endif
