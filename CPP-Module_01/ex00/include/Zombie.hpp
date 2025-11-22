/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:14:16 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:16:52 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>

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
	
	void		randomChump( std::string name );
	Zombie*		newZombie( std::string name );

#endif
