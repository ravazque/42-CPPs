/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:14:16 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 02:51:37 by ravazque         ###   ########.fr       */
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
			std::cout << z->name << " destroyed" << std::endl;
			delete z;
		}
		
		void	setName(std::string zombieName)
		{
			name = zombieName;
		}
		
		void announce( void );
		static Zombie* zombieHorde( int N, std::string name );
};

#endif
