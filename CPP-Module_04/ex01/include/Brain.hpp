/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:31:44 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/23 04:44:06 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <iostream>
# include <string>

typedef std::string string;

class Brain
{
	private:

		string	_ideas[100];

	public:

		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain &operator=(const Brain &src);

		void setIdea(int index, const string &idea);
		string getIdea(int index) const;

};

#endif
