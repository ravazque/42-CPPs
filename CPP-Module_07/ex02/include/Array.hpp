/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:41:17 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/16 14:23:52 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>
# include <cstdlib>
# include <ctime>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &src);
		~Array(void);

		Array	&operator=(const Array &src);
		T		&operator[](unsigned int index);
		T const	&operator[](unsigned int index) const;

		unsigned int	size(void) const;
};

# include "Array.tpp"

#endif
