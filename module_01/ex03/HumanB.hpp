/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:33:31 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 18:36:17 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanA.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* weapon;

    public:
        HumanB(const std::string& name, Weapon* weapon) : name(name), weapon(weapon) {}
        ~HumanB(void);
        void setWeapon(Weapon& newWeapon);
        void attack();
};
