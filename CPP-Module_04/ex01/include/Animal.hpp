/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:11:56 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:43:19 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>
# include <string>
# include <cstdlib>

typedef std::string string;

class Animal
{
	protected:

		string	_type;

	public:

		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();

		Animal &operator=(const Animal &src);

		virtual void makeSound(void)const;
		string getType(void)const;

};

#endif
