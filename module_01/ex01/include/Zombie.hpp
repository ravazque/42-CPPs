/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:14:16 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:06:00 by ravazque         ###   ########.fr       */
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

		void setName(std::string zombieName);
		void announce( void );
		static Zombie* zombieHorde( int N, std::string name );
};

#endif
