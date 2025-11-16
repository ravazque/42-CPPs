/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:14:16 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/16 02:17:03 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:

		std::string name;

	public:

		void destroy( Zombie *z )
		{
			std::cout << z->name << " destroyed\n";
			delete z;
		}

		void announce( void );
		Zombie* newZombie( std::string name );
		void randomChump( std::string name );

};

#endif
