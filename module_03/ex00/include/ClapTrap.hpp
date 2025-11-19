/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:21:24 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 23:10:42 by ravazque         ###   ########.fr       */
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

};

#endif
