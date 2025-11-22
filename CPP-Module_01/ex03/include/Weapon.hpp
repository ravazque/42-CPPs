/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:33:27 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 15:30:18 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class Weapon
{
    private:

        std::string type;

    public:

        Weapon(const std::string& name) : type(name) {}
        const std::string getType();
        void    setType( std::string s);

};
