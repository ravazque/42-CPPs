/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:33:36 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:03:40 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;

    public:
        HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}
        ~HumanA(void);
        void attack();
};
