/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:21:24 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/20 20:06:25 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>

typedef std::string string;

class ClapTrap
{
    private:

        string      _name;
        int         _hit_points;
        int         _energy_points;
        int         _attack_damage;

    public:

        ClapTrap();
        ClapTrap(const string &name);
        ClapTrap(const ClapTrap& copy);
        ~ClapTrap();

        void attack(const string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ClapTrap	&operator=(ClapTrap const &copy);
        
        string const	&get_name(void) const;
		int const		&get_hit_points(void) const;
		int const		&get_energy_points(void) const;
		int const		&get_attack_damage(void) const;

		void			set_name(string const &name);
		void			set_hit_points(int const &value);
		void			set_energy_points(int const &value);
		void			set_attack_damage(int const &value);

};

#endif
