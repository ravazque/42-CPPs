/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:11:56 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 03:44:18 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:

		Brain	*_brain;

	public:

		Cat();
		Cat(const Cat &copy);
		~Cat();

		Cat &operator=(const Cat &src);

		void makeSound(void)const;
		void setIdea(int index, const string &idea);
		void getIdeas(void) const;

};

#endif
