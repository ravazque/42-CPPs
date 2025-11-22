/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:21:24 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/22 19:55:18 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>
# include <string>

class ClapTrap
{
    protected:

        std::string     _name;
        unsigned int    _hit_points;
        unsigned int    _energy_points;
        unsigned int    _attack_damage;

    public:

        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap& copy);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ClapTrap	&operator=(ClapTrap const &copy);

        std::string const		&get_name(void) const;
		unsigned int const		&get_hit_points(void) const;
		unsigned int const		&get_energy_points(void) const;
		unsigned int const		&get_attack_damage(void) const;

		void					set_name(std::string const &name);
		void					set_hit_points(unsigned int const &value);
		void					set_energy_points(unsigned int const &value);
		void					set_attack_damage(unsigned int const &value);

};

#endif
