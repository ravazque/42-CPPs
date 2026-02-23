/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 08:32:30 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/23 23:00:58 by ravazque         ###   ########.fr       */
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
