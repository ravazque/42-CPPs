/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:05:48 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/13 11:22:37 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:

		Serializer(void);
		Serializer(const Serializer &src);
		~Serializer(void);
		Serializer	&operator=(const Serializer &src);

	public:

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

};

#endif
