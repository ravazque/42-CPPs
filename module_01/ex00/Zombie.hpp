/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:14:16 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 21:03:14 by ravazque         ###   ########.fr       */
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

		Zombie();
		Zombie(std::string name);
		
		~Zombie();
		
		void announce( void );

	};
	
	void randomChump( std::string name );
	Zombie* newZombie( std::string name );

#endif
