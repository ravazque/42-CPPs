/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:21:24 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/22 21:13:50 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:

		bool _guarding_gate;

	public:

		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);
		virtual ~ScavTrap();

		ScavTrap &operator=(const ScavTrap &src);

		void attack(const std::string &target);
		void guardGate(void);

	bool const	&get_guarding_gate(void) const;
	void		set_guarding_gate(bool const &value);

};

#endif
