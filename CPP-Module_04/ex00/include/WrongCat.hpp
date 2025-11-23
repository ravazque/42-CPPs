/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:21:06 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:21:07 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

	public:

		WrongCat();
		WrongCat(const WrongCat &copy);
		~WrongCat();

		WrongCat &operator=(const WrongCat &src);

		void makeSound(void)const;

};

#endif
