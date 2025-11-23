/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:11:56 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 03:44:21 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class Dog: public Animal
{
	private:

	public:

		Dog();
		Dog(const Dog &copy);
		~Dog();
		
		Dog &operator=(const Dog &src);

		void makeSound(void)const;

};

#endif
